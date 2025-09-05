#include<bits/stdc++.h>
using namespace std;
int main(){
    int test;
    cin>>test;
    getchar();
    while (test--)
    {
        string s;
    getline(cin,s);
    int firstPart = 0, secondPart = 0;
    for(int i = 0; i< s.length(); i++){
        if(i < 3){
            int tmp = s[i];
            firstPart+=tmp;
        }else{
            int tmp = s[i];
            secondPart+=tmp;
        }
    }
    if(firstPart == secondPart){
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    }
    return 0;
}