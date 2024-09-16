#include<bits/stdc++.h>
using namespace std;
#include"LinkedListClass.C++"

Node *mergeSort(Node *head){
    if(head==NULL|| head->next==NULL){
        return head;
    }
    Node* slow=head;
    Node* fast=head->next;
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    Node* Junction=slow->next;
    slow->next=NULL;
    Node* temp = mergeSort(head);
    Junction = mergeSort(Junction);
   
    
    Node* FinalHead;
    if(temp->data>Junction->data){
        FinalHead=Junction; 
        Junction=Junction->next;
    }
    else{
        FinalHead=temp;
        temp=temp->next;
    }
    Node* curr;
    Node* ptr=FinalHead;
    while(temp!=NULL && Junction!=NULL){
        if(temp->data>Junction->data){
            curr=Junction->next;
            ptr->next=Junction;
            ptr=Junction;
            Junction=curr;
        }
        else{
            curr=temp->next;
            ptr->next=temp;
            ptr=temp;
            temp=curr;
        }
    }
    if(temp==NULL){
        ptr->next=Junction;
    }
    else{
        ptr->next=temp;
    }
    return FinalHead;
}