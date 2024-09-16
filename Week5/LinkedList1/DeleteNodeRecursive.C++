#include<bits/stdc++.h>
using namespace std;
#include"LinkedListClass.C++"

Node* Helper(Node*head,Node*temp,int pos){
	if(temp==NULL){
		return temp;
	}
	if(pos==0){
		Node* a=head->next;
		head=a;
		delete temp;
		return head;
	}
	if(pos==1){
		Node* a=temp->next;
		Node* b=a->next;
		temp->next=b;
		delete a;
		return head;
	}
	Helper(head, temp->next, pos-1);
}


Node *deleteNodeRec(Node *head, int pos) {
	Node* temp=head;
	int len=0;
	while(temp!=NULL){
		temp=temp->next;
		len++;
	}
	if(len<=pos){
		return head;
	}
	return Helper(head, head, pos);

}