import os
import requests
from bs4 import BeautifulSoup
from datetime import datetime
from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
import time

# -------- CONFIG --------
CF_HANDLE = os.getenv("CF_HANDLE")
CF_USER = os.getenv("CF_USER")
CF_PASS = os.getenv("CF_PASS")
REPO_PATH = "."  # GitHub runner current repo
# ------------------------

LOGIN_URL = "https://codeforces.com/enter"
SESSION = requests.Session()


def get_driver():
    """Returns a configured headless Chrome driver"""
    chrome_options = Options()
    chrome_options.add_argument("--headless")
    chrome_options.add_argument("--no-sandbox")
    chrome_options.add_argument("--disable-dev-shm-usage")
    
    # Use the ChromeDriver path from the .yml file
    service = Service("/usr/local/bin/chromedriver")
    driver = webdriver.Chrome(service=service, options=chrome_options)
    return driver


def login_with_selenium(driver):
    """Logs into Codeforces using Selenium"""
    driver.get(LOGIN_URL)
    
    try:
        # Increase the timeout to 20 seconds
        username_field = WebDriverWait(driver, 30).until(
            EC.presence_of_element_located((By.NAME, "handleOrEmail"))
        )
        password_field = driver.find_element(By.NAME, "password")
        
        username_field.send_keys(CF_USER)
        password_field.send_keys(CF_PASS)
        
        driver.find_element(By.CSS_SELECTOR, ".submit").click()

        WebDriverWait(driver, 20).until(
            EC.url_contains("/profile/")
        )
        print("✅ Login successful with Selenium.")
        
        cookies = driver.get_cookies()
        for cookie in cookies:
            SESSION.cookies.set(cookie['name'], cookie['value'])
            
        SESSION.headers = {
            'User-Agent': driver.execute_script("return navigator.userAgent;")
        }
        
    except Exception as e:
        print(f"Login failed: {e}")
        driver.save_screenshot("login_error.png")
        raise


def fetch_submissions(handle):
    """Fetches last 30 submissions using the authenticated session"""
    url = f"https://codeforces.com/api/user.status?handle={handle}&from=1&count=30"
    res = SESSION.get(url).json()
    return res["result"] if res["status"] == "OK" else []


def fetch_code(contest_id, submission_id):
    """Scrapes source code from submission page using the session"""
    url = f"https://codeforces.com/contest/{contest_id}/submission/{submission_id}"
    resp = SESSION.get(url)
    soup = BeautifulSoup(resp.text, "html.parser")
    code_area = soup.find("pre", {"id": "program-source-text"})
    return code_area.text if code_area else None


def save_solution(sub):
    """Saves accepted solution into repo"""
    if sub.get("verdict") != "OK":
        return

    contest_id = sub["contestId"]
    problem_index = sub["problem"]["index"]
    lang = sub["programmingLanguage"]

    ext = ".cpp" if "C++" in lang else ".py" if "Python" in lang else ".txt"
    folder = os.path.join(REPO_PATH, str(contest_id))
    os.makedirs(folder, exist_ok=True)

    file_path = os.path.join(folder, f"{problem_index}{ext}")
    if os.path.exists(file_path):
        return

    print(f"Attempting to fetch code for submission {sub['id']}...")
    code = fetch_code(contest_id, sub["id"])
    if not code:
        print(f"Code for submission {sub['id']} not found.")
        return

    with open(file_path, "w", encoding="utf-8") as f:
        f.write(f"// {sub['problem']['name']}\n")
        f.write(f"// Contest: {contest_id}\n")
        f.write(
            f"// Solved at: {datetime.utcfromtimestamp(sub['creationTimeSeconds']).strftime('%Y-%m-%d %H:%M:%S')}\n\n"
        )
        f.write(code)

    print(f"✅ Saved: {file_path}")


if __name__ == "__main__":
    driver = get_driver()
    try:
        login_with_selenium(driver)
        subs = fetch_submissions(CF_HANDLE)
        for s in subs:
            save_solution(s)
        print("🚀 Sync complete")
    finally:
        driver.quit()
