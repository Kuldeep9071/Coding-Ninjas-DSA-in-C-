#include<bits/stdc++.h>
using namespace std;
#include"LinkedListClass.C++"

Node* evenAfterOdd(Node* head) {
    if(head==NULL || head->next==NULL){
		return head;
	}
	Node* even=NULL;
	Node* odd=NULL;
	Node* evenT=NULL;
	Node* oddT=NULL;
	while(head!=NULL){
		if(head->data%2==1){
			if(odd==NULL){
				odd=head;
				oddT=odd;
				head=head->next;
				oddT->next=NULL;
			}
			else{
				oddT->next=head;
				head=head->next;
				oddT=oddT->next;
				oddT->next=NULL;
			}
		}
		else{
			if(even==NULL){
				even=head;
				evenT=even;
				head=head->next;
				evenT->next=NULL;
			}
			else{
				evenT->next=head;
				head=head->next;
				evenT=evenT->next;
				evenT->next=NULL;
			}
		}
	}
	if(odd!=NULL){
		oddT->next=even;
		return odd;
	}
	return even;	
}