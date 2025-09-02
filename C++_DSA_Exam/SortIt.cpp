#include<bits/stdc++.h>
using namespace std;
void Print_Output(int* A,int n){
    for(int j = 0; j < n; j++){
            cout<<A[j]<<' ';
    } 
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    int A[n];
    for(int i = 0; i < n; i++){
        cin>>A[i];
    }
    sort(A,A+n);
    Print_Output(A,n);
    sort(A,A+n,greater<int>());
    Print_Output(A,n);
    return 0;
}