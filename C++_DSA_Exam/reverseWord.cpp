#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    stringstream ss(s);
    string word;
    string result = "";
    while (ss>>word)
    {
        string reversed = "";
        for(int i = word.length()-1; i >= 0; i--){
            reversed+=word[i];
        }
        result+=reversed;
        result+=" ";
    }
    result.pop_back();
    cout<<result<<endl;
    
    return 0;
}