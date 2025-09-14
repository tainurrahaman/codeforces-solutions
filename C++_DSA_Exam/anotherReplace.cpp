#include<bits/stdc++.h>
using namespace std;
int main(){
    int test;
    cin>>test;
    while (test--)
    {
        string str,searchWord;
    cin>>str>>searchWord;
    size_t pos = 0;
    while ((pos=str.find(searchWord,pos)) != string::npos)
    {
        str.replace(pos,searchWord.length(),"#");
        pos+=searchWord.length();
    }
    
    cout<<str<<endl;
    }
    
    return 0;
}