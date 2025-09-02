#include<bits/stdc++.h>
using namespace std;
int main(){
    int test;
    cin>>test;
    while(test--){
    int n,s;
    cin>>n>>s;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    int flag = 0;
    for(int i = 0; i < n-2; i++){
        for(int j = i+1; j < n-1; j++){
            for(int k = j+1; k < n; k++){
                if((arr[i] + arr[j] + arr[k]) == s){
                    flag = 1;
                }
            }
            if(flag) break;
        }
        if(flag) break;
    }
    if(flag){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    }
    return 0;
}