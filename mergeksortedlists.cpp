#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

class LinkedListNode {
    public:
        int value;
        LinkedListNode *next;

        LinkedListNode(int value) {
            this->value = value;
            this->next = nullptr;
        }
        LinkedListNode() {  // Default constructor
            this->value = 0;
            this->next = nullptr;
        }
};

LinkedListNode* merge(LinkedListNode* list1, LinkedListNode* list2){
    LinkedListNode *curr1 = list1;
    LinkedListNode *curr2 = list2;
    LinkedListNode *mergedList= new LinkedListNode();
    while(curr1 != nullptr && curr2 != nullptr){
        if(curr1->value <= curr2->value){
            mergedList->next = new LinkedListNode(curr1->value);
            curr1 = curr1->next;
        }else{
            mergedList->next = new LinkedListNode(curr2->value);
            curr2 = curr2->next;
        }
    }
    while(curr1 != nullptr){
        mergedList->next = new LinkedListNode(curr1->value);
        curr1 = curr1->next;
    }
    while(curr2 != nullptr){
        mergedList->next = new LinkedListNode(curr2->value);
        curr2 = curr2->next;
    }
    return mergedList;
    
}
LinkedListNode *merge_k_lists(vector<LinkedListNode*> &lists) {
    if(lists.empty()) return nullptr;
    
    LinkedListNode *result = lists[0];
    for(int i = 1; i < lists.size(); i++){
        result = merge(result, lists[i]);
    }
    return result;
}

int main(){

    return 0;
}