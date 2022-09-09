#include<iostream>
using namespace std;

const int maximum = 1000;
int lcsrecursion(string x , string y, int m, int n){
    if(m == 0 || n ==0){
        return 0;
    }

    if(x[m-1] == y[n-1]){
        return 1 + lcsrecursion(x,y,m-1,n-1);
    }else{
        return max(lcsrecursion(x,y,m,n-1) , lcsrecursion(x,y,m-1,n));
    }
}

int lcsdp(string x , string y, int m ,int n , int dp[][maximum]){
    if(m==0 || n==0){
        return 0;
    }

    if(dp[m-1][n-1] != -1){
        return dp[m-1][n-1];
    }

    if(x[m-1] == y[n-1]){
        dp[m-1][n-1] = 1+ lcsdp(x,y,m-1,n-1,dp);
        return dp[m-1][n-1];
    }else{
        dp[m-1][n-1] = max(lcsdp(x,y,m,n-1,dp),lcsdp(x,y,m-1,n,dp));
        return dp[m-1][n-1];
    }
}
int main(){
    string x = "AGGTAB";
    string y = "GXTXAYB";

    int m = x.length();
    int n = y.length();

    int dp[m][maximum];
    memset(dp,-1,sizeof(dp));

    // cout<<lcsrecursion(x,y,m,n)<<endl;

    cout<<lcsdp(x,y,m,n,dp)<<endl;
    return 0;
}