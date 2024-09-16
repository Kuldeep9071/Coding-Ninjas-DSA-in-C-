#include<bits/stdc++.h>
using namespace std;
#include"LinkedListClass.C++"

Node *reverseLinkedListRec(Node *head){
	if(head==NULL){
		return head;
	}
	Node* prev=NULL;
	while (head->next != NULL) {
		Node *nxt = head->next;
		head->next = prev;
		prev = head;
		head = nxt;
	}
	head->next = prev;
	return head;
}