#include<bits/stdc++.h>
using namespace std;
int main(){
   int test;
   cin>>test;
   while (test--)
   {
     int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    if(n % 2 == 1){
        cout<<-1<<endl;
    }else{
        int odd = 0, even = 0;
        for(int i = 0; i < n; i++){
           arr[i]%2 == 0 ? even++ : odd++;
        }
        if(even == odd){
            cout<<0<<endl;
        }else{
            if(even == 1 || odd == 1){
                cout<<1<<endl;
            }else{
                cout<<(abs(even-odd))/2<<endl;
            }
        }
    }
   }
   
    return 0;
}