#include<bits/stdc++.h>
using namespace std;
#include "DoublyLinkedList.C++"


bool palindromeDLL(Node* head){
	if(head==NULL|| head->next==NULL){
		return true;
	}
	Node* temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}

    Node* Front=head;
	while(Front!=NULL){
		if(Front->data != temp->data ){
			return false;
		}
		Front=Front->next;
		temp=temp->prev;
	}
	return true;
}
