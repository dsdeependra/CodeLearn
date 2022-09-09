//longest inscreasing subsequence 

#include<iostream>
#include<algorithm>
using namespace std;

int lisRecusrion(int a[] , int n , int *max_ref){
    if(n == 1){
        return 1;
    }
    int res, max_ending_here=1;

    for(int i =1; i <n; i++){
        res = lisRecusrion(a,i,max_ref);
        if(a[i-1]<a[n-1] && res+1>max_ending_here){
            max_ending_here = res+1;
        }
    }

    if(*max_ref < max_ending_here){
        *max_ref = max_ending_here;
    }
    return max_ending_here;
}

int lis(int a[] , int n){
    int max = 1;
    lisRecusrion(a,n,&max);
    return max;
}
int getLISDP(int a[],int n ){
    int lis[n];
    lis[0] = 1;
    for(int i=1; i<n; i++){
        lis[i] = 1;
        for(int j = 0; j<i; j++){
            if(a[j]<a[i] && lis[i] < lis[j]+1){
                lis[i] = lis[j] + 1;
            }
        }
    }
    return *max_element(lis,lis+n);
}


int main(){
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 }; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    printf("Length of lis is %dn", 
           lis( arr, n ));
    return 0;
}