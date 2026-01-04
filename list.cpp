#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>

using namespace std;

struct listNode {
    int val;
    listNode* next;
    listNode(int x) : val(x), next(nullptr) {}
};
listNode* createLinkedList(const vector<int>& values) {
    if (values.empty()) return nullptr;
    listNode* head = new listNode(values[0]);
    listNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new listNode(values[i]);
        current = current->next;
    }
    return head;
}
void printLinkedList(listNode* head) {
    listNode* current = head;
    while (current) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
} 

void reverseList(listNode*& head){
    listNode* prev = nullptr;
    listNode* current = head;
    listNode* next = nullptr;
    
    while(current != nullptr){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

listNode* reverseListRecursive(listNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    listNode* newHead = reverseListRecursive(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}
void removeKthFromEnd(listNode*& head, int k) {
    listNode* fast = head;
    listNode* slow = head;
    
    for (int i = 0; i < k; ++i) {
        if (fast == nullptr) return; // k is larger than the list size
        fast = fast->next;
    }
    
    if (fast == nullptr) {
        listNode* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    
    while (fast->next != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }
    
    listNode* temp = slow->next;
    slow->next = slow->next->next;
    delete temp;
}
int main() {
    vector<int> values = {1, 2, 3, 4, 5};
    listNode* head = createLinkedList(values);
    printLinkedList(head);
    reverseList(head);
    printLinkedList(head);
    // Free allocated memory (not shown here for brevity)
    return 0;
}
