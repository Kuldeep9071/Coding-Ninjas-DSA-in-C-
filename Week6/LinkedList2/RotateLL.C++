#include<bits/stdc++.h>
using namespace std;
#include"LinkedListClass.C++"

Node *rotate(Node *head, int k) {
     if(head==NULL || head->next==NULL){
          return head;
     }
     if(k==0){
          return head;
     }
     int n=0;
     Node* temp=head;
     while(temp!=NULL){
          n++;
          temp=temp->next;
     }
     if(k==n){
          return head;
     }
     if(k>n){
          k=k%n;
     }
     if(k==0){
          return head;
     }
     temp=head;
     int count=0;
     Node* prev=NULL;
     while(count!=n-k){
          count++;
          prev=temp;
          temp=temp->next;
     }
     Node* newhead=temp;
     prev->next=NULL;
     while(temp->next!=NULL){
          temp=temp->next;
     }
     temp->next=head;
     return newhead;
}