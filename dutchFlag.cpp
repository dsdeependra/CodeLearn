#include<iostream>

using  namespace std;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortByColor(int arr[]){
    int n = sizeof(arr)/sizeof(arr[0]);
    int low = 0;
    int high = n-1;
    int mid =0;

    while(mid <= high){
        switch(arr[mid]){
            case 0:
                swap(&arr[low++],&arr[mid++]);
            break;
            case 1:
                mid++;
            break;
            case 2:
                swap(&arr[mid],&arr[high--]);
            break;
        }
    }
}
int main(){

    int arr[] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
   

    sortByColor(arr);
    int n = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}