#include<bits/stdc++.h>
using namespace std;
#include"LinkedListClass.C++"

Node *swapNodes(Node *head, int i, int j){
	if(head==NULL || head->next==NULL || i==j){
		return head;
	}
	
	if(i==0){
		Node* temp=head;
		Node* prev=NULL;
		int count=0;
		while(count!=j){
			count++;
			prev=temp;
			temp=temp->next;
		}
		Node* a=temp->next;
		Node* b=head->next;
		prev->next=head;
		head->next=a;
		Node* newhead=temp;
		newhead->next=b;
		return newhead;
	}
	else if(j==0){
		Node* temp=head;
		Node* prev=NULL;
		int count=0;
		while(count!=i){
			count++;
			prev=temp;
			temp=temp->next;
		}
		Node* a=temp->next;
		Node* b=head->next;
		prev->next=head;
		head->next=a;
		Node* newhead=temp;
		newhead->next=b;
		return newhead;
	}
	else{
		Node* temp=head;
		int n=0;
		while(temp!=NULL){
			n++;
			temp=temp->next;
		}
		if(i>=n || j>=n){
			return head;
		}

		Node* temp1=head;
		Node* prev1=head;
		int count=0;
		while(count!=i){
			count++;
			prev1=temp1;
			temp1=temp1->next;
		}
		Node* temp2=head;
		Node* prev2=head;
		count=0;
		while(count!=j){
			count++;
			prev2=temp2;
			temp2=temp2->next;
		}
		if(i-j==1){
			Node* a=temp1->next;
			prev2->next=temp1;
			temp1->next=temp2;
			temp2->next=a;
			return head;
		}
		else if(j-i==1){
			Node* a=temp2->next;
			prev1->next=temp2;
			temp2->next=temp1;
			temp1->next=a;
			return head;
		}
		else{
			Node* After1=prev1->next->next;
			Node* After2=prev2->next->next;
			prev1->next=temp2;
			temp2->next=After1;
			prev2->next=temp1;
			temp1->next=After2;	
		}
		return head;
	}
}