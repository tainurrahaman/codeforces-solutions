#include<bits/stdc++.h>
using namespace std;
int Equation_Sum(int x, int n, int sum){
    for(int i = 2; i <= n; i+=2){
        int init = x;
        for(int j = 1; j < i; j++){
            init = init * x;
        }
        sum+=init;
    }
    return sum;
}
int main(){
    int x,n;
    cin>>x>>n;
    int sum = 0;
    int result = Equation_Sum(x,n,sum);
    cout<<result<<endl;
    return 0;
}