#include<bits/stdc++.h>
using namespace std;
#include"LinkedListClass.C++"

Node* skipMdeleteN(Node *head, int M, int N){
	if(head==NULL || M==0){
		return NULL;
	}
	if(N==0){
		return head;
	}
	Node* temp=head;
	while(temp!=NULL){
		int count=0;
		Node* prev=temp;
		while(count!=M && temp!=NULL){
			count++;
			prev=temp;
			temp=temp->next;
		}
		count=0;
		while(count!=N && temp!=NULL){
			Node* a=temp;
			Node* b=temp->next;
			prev->next=b;
			temp=temp->next;
			count++;
			delete a;
		}
	}
	return head;
	
}