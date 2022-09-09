

#include<iostream>

using namespace std;

#define mod 1000000007;


long getFact(int n){
    long fact[n];
        if(n == 0 || n == 1){
            return n;
        }
        fact[0] = 1;
        fact[1] = 1;
        fact[2] = 2;
        // int temp;
        for(int i=3;i<=n;i++){
            fact[i] = (i * fact[i-1]) % mod;
            
        }
        
        return fact[n];
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        long result = getFact(n);
        cout<<result<<endl;
    }
    return 0;
}

      
