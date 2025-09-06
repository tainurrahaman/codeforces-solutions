#include<bits/stdc++.h>
using namespace std;

int main() {
    string text ;
    getline(cin,text);
    string old_sub = "EGYPT";
    string new_sub = " ";

    int pos = text.find(old_sub);
    while (pos != string::npos) {
        text.replace(pos, old_sub.length(), new_sub);
        pos = text.find(old_sub, pos + new_sub.length()); 
    }
    cout << text << endl;

    return 0;
}