#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int total_balloons = 0;
    unordered_set<char> solved_problems;

    for (char problem : s) {
        if (solved_problems.find(problem) == solved_problems.end()) {
            total_balloons += 2;
            solved_problems.insert(problem);
        } else {
            total_balloons += 1;
        }
    }
     cout << total_balloons << endl;
}

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}