#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    string givenWord;
    cin>>givenWord;
    int count = 0;

    stringstream ss(s);
    string word;
    while (ss>>word)
    {
        if(word == givenWord) count++;
    }

    cout<<count;
    
    return 0;
}