#include<bits/stdc++.h>
using namespace std;
#include"LinkedListClass.C++"

Node *reverseLinkedList(Node *head) {
	if(head==NULL || head->next==NULL){
		return head;
	}
    Node* curr=head;
	Node* Prev=NULL;

	while(curr->next!=NULL){
		Node* front=curr->next;
		curr->next=Prev;
		Prev=curr;
		curr=front;
	}
	curr->next=Prev;
	return curr;
}