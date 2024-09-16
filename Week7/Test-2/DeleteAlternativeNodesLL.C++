#include<bits/stdc++.h>
using namespace std;
#include"LinkedListClass.C++"


void deleteAlternateNodes(Node *head) {
    if(head==NULL || head->next==NULL){
        return;
    }
    Node* temp=head;
    while(temp!=NULL){
        if(temp->next!=NULL){
            Node* a=temp->next;
            temp->next=a->next;
        }
        temp=temp->next;
    }
}