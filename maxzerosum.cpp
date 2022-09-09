#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

int findMaxZeroSum(int A[], int n){
    map<int,int>m;
    //m[A[0]] = 0;
    int sum =0;
    int max_len = 0;
    for(int i=0;i<n;i++){
        sum +=A[i];
        if(A[i] == 0 && max_len ==0){
            max_len = 1;
        }
        if(sum ==0){
            max_len = i+1;
        }
        if(m.find(sum) != m.end()){
            max_len = max(max_len,i-m[sum]);
        }else{
            m[sum] = i;
        }
    }
    return max_len;
}

int main(){
    int A[]={ 15, -2, 2, -8, 1, 7, 10, 23 };
    int n = sizeof(A)/sizeof(A[0]);
    int result = findMaxZeroSum(A,n); 
    cout<<result<<endl;   
    return 0;
}