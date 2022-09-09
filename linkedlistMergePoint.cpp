#include<iostream>
#include<cstdio>

using namespace std;

struct node{
	int data;
	struct node* next;
}

int length(struct node *head){
	int len =0;
	while(head!= NULL){
		len++;
		head = head->next;
	}
	return head;
}

struct node* findMergePoint(struct node  *A, struct node *B){
	int lengthA = length(A);
	int lengthB = length(B);
	int d = lengthB - lengthA;
	
	if(lengthA > lengthB){
		//swap A to B
		struct node* temp;
		temp = A;
		A = B;
		B = temp;
		d = lengthA - lengthB;		
	}		
	
	for(int i=0;i<d;i++){
		B = B->next;			
	}
		
	while(A!= NULL || B != NULL){
		if(A == B)
		{
			return A;
		}
		A = A->next;
		B = B->next;
	}
	return NULL;
}

struct node* reverseList(struct node *head){
	
	struct node* temp = head;
	struct node* prev = NULL;
	
	while(temp !=NULL){
		temp = head->next;
		temp->next = prev;
		prev = head;
		head = temp;
	}
	
	return head;
	
}

int main(){
	//finding mergepoint
}
