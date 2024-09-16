#include<bits/stdc++.h>
using namespace std;
#include"LinkedListClass.C++"

void reverse(Node* head){
    if(head==NULL || head->next==NULL){
        return;
    }

    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL){
        Node* a=temp->next;
        temp->next=prev;
        prev=temp;
        temp=a;
    }
}
Node* NextLargeNumber(Node *head) {
    if(head==NULL){
        return head;
    }

    Node * K=head;
    while(K!=NULL){
        if(K->data==9){
            K=K->next;
        }
        else{
            break;
        }
    }
    if(K==NULL){
        Node* V=head;
        while(V!=NULL){
            V->data=0;
            V=V->next;
        }
        Node* G=new Node(1);
        G->next=head;
        return G;
    }

    Node* prev=NULL;
    Node* newhead=head;
    Node* curr=NULL;
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    if(temp->data!=9){
        temp->data+=1;
        return head;
    }
    reverse(head);
    curr=temp;
    while(temp->data==9){
        temp->data=0;
        temp=temp->next;
        prev=temp;
    }
    if(temp!=NULL){
        temp->data+=1;
        reverse(curr);
        return newhead;
    }
}


/*
Problem statement
Given a large number represented in the form of a linked list.
 Write code to increment the number by 1 in-place(i.e. without using extra space).

Note: You don't need to print the elements, just update the elements and 
return the head of updated LL. Input Constraints:

1 <= Length of Linked List <=10^6.

Detailed explanation ( Input/output format, Notes)

Sample Input 1 :
3 9 2 5 -1
Sample Output 1 :
3 9 2 6
Sample Input 2 :
9 9 9 -1
Sample Output 1 :
1 0 0 0 
*/