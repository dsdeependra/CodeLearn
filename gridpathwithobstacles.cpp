int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    int m = A.size();
    int n = A[0].size();
    
    int B[m][n];
    
    if(A[0][0] == 0){
        B[0][0] = 1;
    }else{
        B[0][0] = 0;
    }
    
    for(int i=1;i<m;i++){
        if(A[i][0] == 0){
            B[i][0] = B[i-1][0];
        }else{
            B[i][0] = 0;
        }
    }
    
    for(int i =1;i<n;i++){
        if(A[0][i] == 0){
            B[0][i] = B[0][i-1];
        }else{
            B[0][i] = 0;
        }
    }
    
    
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(A[i][j] == 0){
                B[i][j] = B[i-1][j] + B[i][j-1];
            }
        }
    }
    
    return B[m-1][n-1];
    
}
