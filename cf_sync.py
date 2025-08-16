import os
import requests
from bs4 import BeautifulSoup
from datetime import datetime

# -------- CONFIG --------
CF_HANDLE = os.getenv("CF_HANDLE")
REPO_PATH = "."  # GitHub runner current repo
SESSION_PATH = os.getenv("CF_SESSION")
# ------------------------

SESSION = requests.Session()

def load_session_from_file(path):
    """Loads session cookies from a file."""
    try:
        with open(path, 'r') as f:
            cookies = f.read().strip().split(';')
            for cookie in cookies:
                name, value = cookie.split('=', 1)
                SESSION.cookies.set(name, value)
        print("✅ Session loaded from file.")
    except Exception as e:
        print(f"Error loading session: {e}")
        raise Exception("Failed to load session from file.")


def fetch_submissions(handle):
    """Fetch last 30 submissions"""
    url = f"https://codeforces.com/api/user.status?handle={handle}&from=1&count=30"
    res = SESSION.get(url).json()
    return res["result"] if res["status"] == "OK" else []


def fetch_code(contest_id, submission_id):
    """Scrape source code from submission page"""
    url = f"https://codeforces.com/contest/{contest_id}/submission/{submission_id}"
    resp = SESSION.get(url)
    soup = BeautifulSoup(resp.text, "html.parser")
    code_area = soup.find("pre", {"id": "program-source-text"})
    return code_area.text if code_area else None


def save_solution(sub):
    """Save accepted solution into repo"""
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
    load_session_from_file(SESSION_PATH)
    subs = fetch_submissions(CF_HANDLE)
    for s in subs:
        save_solution(s)
    print("🚀 Sync complete")
