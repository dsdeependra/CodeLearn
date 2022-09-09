#include <iostream>
#include <cstdio>

using namespace std;
#define maxnumber 1000
int main(){
    int a,b,c;
    cin>>c>>b>>a;

    int v;
    cin>>v;
    int P[v];
    int T[maxnumber];
    for(int i=0;i<n;i++){
        cin>>P[i];
    }
    memset(T,3,sizeof(T));
    for(int i=0;i<n;i++){
        if(P[i] <=a && P[i] >=1){
            T[P[i]] = 1;
        }else{
            T[P[i]] = 1;
        }
    }
    int answer = 0;
    for(int i=0;i<maxnumber;i++){
        cout<<T[i]<<" ";
        if(T[i] == T[i+1] && (T[i] == 0 || T[i] == 1)){
            answer++;
        }else if(T[i] == T[i+1] && (T[i] == 0 || T[i] == 1)){
            answer +=2;
        }
    }

    return 0;
}