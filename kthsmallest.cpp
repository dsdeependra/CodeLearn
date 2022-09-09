#include<iostream>
#include<climits>

using namespace std;

void swap(int *a,int *b);

class MinHeap{
        int *harr;
        int capacity;
        int heap_size;
    public:
        MinHeap(int a[],int size);
        void minHeapify(int i);
        int parent(int i){
            return (i-1)/2;
        }
        int left(int i){
            return 2*i+1;
        }
        int right(int i){
            return 2*i+2;
        }

        int extractMin();
        int getMin();
};

MinHeap::MinHeap(int a[],int size){
    heap_size =size;
    harr = a;
    int i= (heap_size-1)/2;

    while(i>=0){
        minHeapify(i);
    }   
}

void minHeapify(int i){
    
}