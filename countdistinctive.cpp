#include<iostream>
#include<map>

using namespace std;

void countDistinct(int A[], int k, int n){
    map<int,int> m;
    int initK = k;
    int distcount =0;
    for(int i =0; i<k; i++){
        if(m.find(A[i]) != m.end()){ //found
            m[A[i]]++;
        }else{
            m[A[i]] = 1;
            distcount++;
        }
    }
    cout<<distcount<<endl;
    for(int i= k ;i<n;i++){
        if(m[A[i-k]] == 1){
            distcount--;
        }
        m[A[i-k]]--;

        // if(m[A[i]] == 0){
        //     distcount++;
        // }
        // m[A[i]]++;

        if(m.find(A[i]) != m.end() && m[A[i]] !=0){ //found
            m[A[i]]++;
        }else{
            m[A[i]] = 1;
            distcount++;
        }
        cout<<distcount<<endl;
    }

}

int main(){
    int arr[] = {1, 2, 1, 3, 4, 2, 3}; 
    int size = sizeof(arr)/sizeof(arr[0]); 
    int k = 4; 
    countDistinct(arr, k, size); 
    return 0;
}