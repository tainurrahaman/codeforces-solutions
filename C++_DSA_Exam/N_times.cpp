#include<bits/stdc++.h>
using namespace std;
void N_times_Print(int n, char c){
    for(int i = 0; i < n; i++){
        cout<<c<<" ";
    }
}
int main(){
    int test;
    cin>>test;
    while (test--)
    {
    int n;
    cin>>n;
    cin.ignore();
    char c;
    cin>>c;
    N_times_Print(n,c);
    cout<<endl;
    }
    
    return 0;
}