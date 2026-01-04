#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

//Design Strategy #1- Brute Force

void selectionSort(vector<int>&arr){
    int n = arr.size();
   
    for(int i = 0;i<n;i++){
        int minValueIndex = i;
        for(int j=i;j<n;j++){
            if(arr[j] < arr[minValueIndex]){
                minValueIndex = j;
            }
        }
        swap(arr[i],arr[minValueIndex]);
    }    
}

void bubbleSort(vector<int>&arr){
    int n = arr.size();
    for(int i=0;i<n;i++){
        for(int j=n-1;j>i; j--){
            if(arr[j] < arr[j-1]){
                swap(arr[j],arr[j-1]);
            }
        }
    }
}

//Design Strategy - #2- Decrease and Conquer , Decrease the
//problem of size n to size n-1

void InsertionSort(vector<int>&arr){
    int n = arr.size();
    
        for(int i=0;i<n;i++){
           int temp = arr[i];
           int red = i-1;
            while(arr[red] > temp && red>=0){
                arr[red+1] = arr[red];
                red--;
            }
            arr[red+1] = temp;
        }
    
}

//Design Strategy #3- Divide and Conquer . divide the problem into multiple 
//smaller instance (mostly2 )

void MergeSortUtil(vector<int>&arr, int start, int end){
    if(start >= end){
        return;
    }
    int mid = start + (end-start)/2;
    MergeSortUtil(arr, start, mid);
    MergeSortUtil(arr, mid+1, end);
    //Now Merge
    int i = start, j = mid+1;
    vector<int>auxArr;
    while(i<=mid && j<=end){
       // std::cout<<arr[i]<<" "<<arr[j];
        if(arr[i]<=arr[j]){
            auxArr.push_back(arr[i]);
            i++;
        }else{
            auxArr.push_back(arr[j]);
            j++;
        }
    }
    

    while(i<=mid){
        auxArr.push_back(arr[i]);
        i++;
    }
    while(j<=end){
        auxArr.push_back(arr[j]);
        j++;
    }
    for (int k = 0; k < auxArr.size(); ++k) {
        arr[start + k] = auxArr[k];
    }
}

void MergeSort(vector<int>&arr){
    int n = arr.size();
    MergeSortUtil(arr,0,n-1);
}

void QuickSortUtil(vector<int>&arr, int start, int end){
    if(start>=end){
        return;
    }
    //randomized quick sort- get the pivotindex randomly from start->end and swap with start and continue
    int pivot = (std::rand() % (end-start+1))+start;
    swap(arr[pivot],arr[start]);
    //considering start as pivot element
    //lomuto's partitioning
    int smaller = start;
    for(int bigger = start+1;bigger<=end;bigger++){
        if(arr[bigger] < arr[start]){
            smaller++;
            swap(arr[smaller],arr[bigger]);
        }
    }
    swap(arr[start],arr[smaller]);

    //left partiion of pivot
    QuickSortUtil(arr,start,smaller-1);
    //right partition of pivot
    QuickSortUtil(arr,smaller+1,end);

}

void QuickSort(vector<int>&arr){
    int n = arr.size();
    QuickSortUtil(arr, 0, n-1);
}


//heapify the tree , rooted at index i
void heapify(vector<int>&arr, int n , int i){
    int largest = i;
    int left = 2*i+1;
    int right = 2*i +2;

    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }
    if(right <n && arr[right] > arr[largest]){
        largest = right;
    }
    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr,n,largest);
    }

}
void BuildHeap(vector<int>&arr){
    int n = arr.size();
    //started from last non leaf node
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }

}
void HeapSort(vector<int>&arr){
    BuildHeap(arr);
    int n = arr.size();
    for(int i= n-1;i>0;i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }

}

//kth largest element using quickselect method (
//which is basically quick sort method using any partitioning method)

int main() {
    vector<int> numbers = {34, 7, 23, 32, 5, 62};
    
    cout << "Original array: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    //sort(numbers.begin(), numbers.end());
    // selectionSort(numbers);
    // bubbleSort(numbers);
    //InsertionSort(numbers);
    //MergeSort(numbers);
    //QuickSort(numbers);
    HeapSort(numbers);
    cout << "Sorted array: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}