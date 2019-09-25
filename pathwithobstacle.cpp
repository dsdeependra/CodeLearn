#include<iostream>

using namespace std;

int numberofpaths(int a[][], int m, int n){
    int b[m][n];
    for(int i=0;i<m;i++){
        if(a[i][0] == 1){
            b[i][0] = 0;
        }else{
            b[i][0] = 1;
        }
    }
    
    for(int i=1;i<n;i++){
        if(a[0][i] == 1){
            b[0][i] = 0;
        }else{
            b[0][i] = 1;
        }
    }

    for(int i =1;i<m;i++){
        for(int j =1;i<n;j++){
            b[i][j] = b[i-1][j] + b[i][j-1];
        }
    }

    return b[m-1][n-1];
}

int main(){
   // int a[][] = []
    int m = sizeof(a)/sizeof(a[0][0]);
    int n = sizeof(a[0])/sizeof(a[0][0]);
    numberofpaths(a,m,n);
}