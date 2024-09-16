#include<bits/stdc++.h>
using namespace std;
#include"LinkedListClass.C++"

int Helper(int ans,Node* head,int n){
	if(head==NULL){
		return 0;
	}
	if(head->data==n){
		return 0;
	}
	return 1+Helper(ans,head->next, n);
}

int findNodeRec(Node *head, int n){
	if(head==NULL){
		return -1;
	}
	Node* temp=head;
	int len=0;
	while(temp!=NULL){
		temp=temp->next;
		len++;
	}
	int ans=Helper(len, head, n);
	if(ans==len){
		return -1;
	}
	return  ans;
}