int Solution::minPathSum(vector<vector<int> > &A) {
    
    //vector<vector<int> > B;
    if(A.size() == 0){
        return 0;
    }
    
    int m = A.size();
    int n = A[0].size();
    
    vector<vector<int> > B(m, vector<int>(n));
    int sum;
    B[0][0] = A[0][0];
    for(int i=1; i<n; i++){
        B[0][i] = sum + A[0][i];
        sum = B[0][i];
    }
    sum =0;
    for(int i=1; i< m;i++){
       B[i][0] = sum + A[i][0];
        sum = B[i][0];
    }
    
    for(int i = 1; i < rows; i++){
        for(int j = 1; j < cols; j++){
            temp[i][j] = A[i][j] + min(temp[i-1][j], temp[i][j-1]);
        }
    }
    
    
    for(int i =1; i< m; i++){
        for(int j=1; j < n; j++){
          //  cout<<min(B[i-1][j] , B[i][j-1])<<endl;
            B[i][j] = min(B[i-1][j] , B[i][j-1]) + A[i][j];
        }
    }
    
    return B[m-1][n-1];
}
