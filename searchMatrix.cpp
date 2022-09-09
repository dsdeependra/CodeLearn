#include<iostream>
#include<vector>

using namespace std;

int returnRow(vector<vector<int> > &A,int B){
    int low = 0;
    int high = A.size();
    int cols = A[0].size();
    while(low < high){
        int mid = (low+high)/2;
        if(A[mid][0] >= B && A[mid][cols-1] <= B){
            return mid;
        }
        if(B < A[mid][0]){
            high = mid-1;
        }
        if(B > A[mid][cols-1]){
            low = mid+1;
        }
    }
    return -1;
}

int main() {
    int row,col;
     int B;
     cin>>row>>col;
     cin>>B;
     vector<vector<int> > A;
     for(int i =0;i<row;i++){
         vector<int>vec;
         for(int j =0;j<col;j++){
             int temp;
             cin>>temp;
             vec.push_back(temp);
         }
         A.push_back(vec);
     }
    int desiredRow = returnRow(A,B);
    int low = 0;
    int high = A[0].size();
    
    while(low<high){
        int mid = (low+high)/2;
        
        if(A[desiredRow][mid] == B){
            cout<<"found it";
            break;
        }
        
        if(A[desiredRow][mid] < B){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    cout<<"not found";
    return 0;
    
    
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
