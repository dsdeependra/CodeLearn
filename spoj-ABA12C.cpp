#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int P[k+1];int ans[k+1];
        
        for(int i=1;i<=k;i++){
            int temp;
            cin>>temp;
            P[i] = temp; ans[i] = temp;

        }
        for(int i=2;i<=k;i++){
            for(int j = 1; j<=i ;j++){
                if(ans[j] == -1 || P[i-j] == -1){
                    continue;
                }
                if(ans[i] == -1){
                    ans[i] = ans[j] + P[i-j];
                }else{
                    ans[i] = min(ans[i],P[i-j] + ans[j]);
                }
            }
        }

        if(k==0){
            cout<<"0"<<endl;
        }else{
            cout<<ans[k]<<endl;
        }

    }
}