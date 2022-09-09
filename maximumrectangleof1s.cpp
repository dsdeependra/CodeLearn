#include<iostream>
#include<cstring>

using namespace std;
// this is to find the square only not the rectangle
void printMaximumRectangle(int master[][],int m, int n){
    int slave[m][n];
    for(int i=0; i<m; i++){
        slave[i][0] = master[i][0]
    }
    for(int i = 0; i<n;i++){
        slave[0][i] = master[0][i];
    }

    for(int i=1;i<m;i++){
        for(int j = 1;j<n ; j++){
            if(master[i][j] == 1){
                slave[i][j] = minimum(slave[i-1][j] , slave[i][j-1], slave[i-1][j-1]) + 1;
            }
            else{
                slave[i][j] = 0;
            }
        }
    }

    //get the maximum value in the slave array
    int max = slave[0][0];
    int max_i = 0;
    int max_j = 0;
    for(int i =0 ;i <m; i++){
        for(int j = 0 ; j<n;j++){
            if(max < slave[i][j]){
                max = slave[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }

    //the final matrix will be of size max and starting backward from (max_i,max_j)








}


int main(){
    
    return 0;
} 