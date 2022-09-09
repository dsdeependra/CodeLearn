#include<iostream>
#include<vector>

using namespace std;



int getSingleNumber(int A[],int size){
    
 if(size == 0){
        return 0;
    }
    
    int first = 0, second = 0;
    for(int i = 0; i < size; i++){
        second = second | (first & A[i]);
        first = first ^ A[i];
        int check = ~(first & second);
        first = first & check;
        second = second & check;
    } 
    
    return first;

}

int main(){
    int A[] = {1,2,4,3,3,2,2,3,1,1};
    int size = sizeof(A)/sizeof(A[0]);
    int res = getSingleNumber(A,size);
    cout<<res<<endl;
    return 0;
}