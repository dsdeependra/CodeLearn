#include<iostream>
#include<vector>

using namespace std;

vector<vector<int> > getSpiral(int A){
      int n = 2 * A -1;
    int arr[n][n];
   int rows = n;
   int cols = n;
    memset(arr, 0, sizeof(arr[0][0]) * rows * cols);
   
        //if (rows == 0) return vector<int> ();
        //int cols = matrix[0].size();
        int row = 0, col = 0, layer = 0;
        //vector<int> res;
        //res.push_back(matrix[0][0]);
        //int layer = 0;
        int dir = 1;
        int step;
        for (step = 1; step <= rows * cols; step++) {
            switch(dir) { // based on dir, check and change dir, then move on
            case 1: // supposed to go right
                if (col == cols - layer-1) { // reach right bound
                    arr[row][col] = A;                      
                    row++;
                    dir = 2;
                }
                else {
                    //cout<<row<<" "<<col<<" "<<A<<endl;;
                    arr[row][col] = A;  
                    //cout<<arr[row][col]<<endl;;                     
                    col++;
                }
                break;
            case 2: // supposed to go down
                if (row == rows - layer-1) { // reach downside bound
                    arr[row][col] = A; 
                    col--;
                    dir = 3;
                }
                else {
                    //cout<<row<<" "<<col<<" "<<A<<endl;;
                    arr[row][col] = A;
                    row++;
                }
                break;
            case 3: // supposed to go left
                if (col == layer) { // reach left bound
                    arr[row][col] = A;
                    row--;
                    dir = 4;
                }
                else {
                    arr[row][col] = A;
                    col--;
                }
                break;
            case 4: // supposed to go up
                if (row == layer + 1) { // reach upside bound
                    arr[row][col] = A;
                    col++;
                    dir = 1;
                    A--;
                    layer++;
                }
                else {
                    arr[row][col] = A;
                    row--;
                }
                break;
            }
            //cout<<arr[row][col]<<endl;
            //res.push_back(matrix[row][col]);
        }
        //return res;
        vector<vector<int> > res;
        for(int i = 0; i<n;i++){
            vector<int> res1;
            for(int j = 0;j<n;j++){
                res1.push_back(arr[i][j]);
            }
            res.push_back(res1);
            //cout<<endl;
        }

   
    return res;
}

int main(){
    int A;
    cin>>A;
    vector<vector<int> > res = getSpiral(A);

}