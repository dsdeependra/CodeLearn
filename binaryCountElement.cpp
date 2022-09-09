#include <iostream>
#include<vector>

using namespace std;


int binarySearch(int A[] , int n , int B , bool firstSearch){
    
    int low = 0,high = n-1;
    
    int result = -1;
    while(low <= high){
        int mid = (low+high)/2;
        //cout<<low<<" "<<high<<" "<<mid<<endl;
        if(A[mid] == B){
            result = mid;
            if(firstSearch){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
            //cout<<"hello "<<result<<endl;
            //return result;
        }else if(A[mid] > B ){
             high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    //cout<<"hello"<<result;
    return result;
}



int main(){

    int A[]= {5, 7, 7, 8, 8, 10};
    int B = 8;
    int n = sizeof(A)/sizeof(A[0]);
    //cout<<n<<endl;
    int firstIndex = binarySearch(A,n,B,true);
    int lastIndex;
    if(firstIndex == -1){
        return 0;
    }
    else{
         lastIndex = binarySearch(A,n,B,false);
    }
    //cout<<firstIndex<<" "<<lastIndex<<endl;
    int res =  lastIndex - firstIndex + 1;

    cout<<res<<endl;
    return 0;
}