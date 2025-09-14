#include<bits/stdc++.h>
using namespace std;
int main(){
    string name;
    getline(cin,name);
    stringstream ss(name);
    string word;
    int flag = 0;
    while (ss>>word)
    {
        if(word == "Jessica"){
        flag = 1;
        break;
    }
    }
    if(flag){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    return 0;
}