#include<iostream>
#include<vector>

using namespace std;

int getMaxDiff(int A[], int n){
   // int n = sizeof(A)/sizeof(A[0]);

    if(n<2){ 
        return -1;
    }
    int maxDiff =0;
    int minNum = A[0];

    for(int i =0;i<n-1;i++){
        maxDiff = max(maxDiff , A[i+1]-minNum);
        minNum = min(minNum , A[i+1]);
    }
    return maxDiff;

}

int main(){
    int A[] = {2,3,10,6,4,8,1};
    int n = sizeof(A)/sizeof(A[0]);
    int result = getMaxDiff(A,n);
    return 0;
}