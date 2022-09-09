#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

int getpow(int a, int n, int d){
    int ans =1;
    long long square = a;
    if(a =0){
        return 0;
    }
    if(n =0){
        return 1;
    }
    while(n!=0){
        if(n%2){
            ans = ((ans%d)*(square %d))%d;
        }
        square=((square%d)*(square%d))%d;
        n=n/2;
        if(ans>d)
            ans=ans%d;
    }
    int X = ans;
    int Y = d;
    int result = X % Y + (X % Y < 0 ? Y : 0);
    return result;
}

int main(){
    int a,n,d;
    cin>>a>>n>>d;
    int result = getpow(a,n,d);
    cout<<result<<endl;

}