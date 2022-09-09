string Solution::longestPalindrome(string A) {
    
    int n = A.size(); // get length of input string
    bool table[n][n];
    memset(table, 0, sizeof(table));
 
    
    int maxLength = 1;
    for (int i = 0; i < n; ++i)
        table[i][i] = true;
 
    
    int start = 0;
    for (int i = 0; i < n-1; ++i)
    {
        if (A[i] == A[i+1])
        {
            table[i][i+1] = true;
            start = i;
            maxLength = 2;
        }
    }
 
    for (int k = 3; k <= n; ++k)
    {
        for (int i = 0; i < n-k+1 ; ++i)
        {
            int j = i + k - 1;
            if (table[i+1][j-1] && A[i] == A[j])
            {
                table[i][j] = true;
                if (k > maxLength)
                {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }
 
   
   string result;
   int low = start;
   int high = start + maxLength -1;
     for( int i = low; i <= high; ++i )
       result += A[i];
       
      return result;
}
