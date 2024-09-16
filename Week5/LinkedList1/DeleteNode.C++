#include<bits/stdc++.h>
using namespace std;
#include"LinkedListClass.C++"

Node *deleteNode(Node *head, int pos){
	if(head==NULL){
		return head;
	}

	if(pos==0)	return head->next;
	Node*Temp=head;
	int n=0;
	while(Temp!=NULL){
		n++;
		Temp=Temp->next;
	}
	if(pos>=n){
		return head;
	}

	int count=0;
	Node* temp=head;
	while(count<pos-1 && temp!=NULL){
		count++;
		temp=temp->next;
	}

	if(temp!=NULL){
		Node *a=temp->next;
		Node *b=a->next;
		delete a;
		if(b!=NULL){
			temp->next=b;
		}
		else{
			 temp->next=NULL;
		}
	}
	return head;
}
