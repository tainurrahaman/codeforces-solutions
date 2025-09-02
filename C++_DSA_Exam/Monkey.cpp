#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    while (getline(cin,str))
    {
    str.erase(remove(str.begin(),str.end(),' '),str.end());
    sort(str.begin(),str.end());
    cout<<str<<endl;
    }
    
    return 0;
}