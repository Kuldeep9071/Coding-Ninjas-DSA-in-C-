#include<bits/stdc++.h>
using namespace std;
#include"LinkedListClass.C++"

Node* reverse(Node*head){
	if(head==NULL){
		return head;
	}
	Node* prev=NULL;
	while(head->next !=NULL){
		Node* nxt=head->next;
		head->next=prev;
		prev=head;
		head=nxt;
	}
	head->next=prev;
	return head;
}

bool isPalindrome(Node *head){
	if(head==NULL|| head->next==NULL){
		return true;
	}
	Node* slow=head;
	Node* fast=head->next;
	while(fast!=NULL && fast->next!=NULL){
		slow=slow->next;
		fast=fast->next->next;
	}
	Node* tail=reverse(slow->next);
	slow->next=NULL;
	while(tail!=NULL){
		if(head->data!=tail->data){
			return false;
		}
		head=head->next;
		tail=tail->next;
	}
	return true;
}