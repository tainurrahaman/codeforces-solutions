#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    getline(cin,s);
    int count = 0;
    bool in_word = false;

    for(char c:s){
        if(isalpha(c)){
            if(!in_word){
                count++;
                in_word = true;
            }
        }else{
            in_word = false;
        }
    }
    cout<<count<<endl;
    return 0;
}