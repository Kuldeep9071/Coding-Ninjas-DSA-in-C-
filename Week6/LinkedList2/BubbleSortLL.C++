#include<bits/stdc++.h>
using namespace std;
#include"LinkedListClass.C++"

Node *bubbleSort(Node *head){
	if(head==NULL || head->next==NULL){
		return head;
	}
	Node* i=head;
	while(i->next!=NULL){
		Node* j=head;
		while(j->next!=NULL){
			if(j->data>j->next->data){
				int a=j->data;
				j->data=j->next->data;
				j->next->data=a;
			}
			j=j->next;
		}
		i=i->next;
	}
	return head;
}