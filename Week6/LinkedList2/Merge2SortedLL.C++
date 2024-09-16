#include<bits/stdc++.h>
using namespace std;
#include"LinkedListClass.C++"

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2){
     if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    Node* FinalHead;
    if(head1->data>head2->data){
        FinalHead=head2; 
        head2=head2->next;
    }
    else{
        FinalHead=head1;
        head1=head1->next;
    }
    Node* curr;
    Node* ptr=FinalHead;
    while(head1!=NULL && head2!=NULL){
        if(head1->data>head2->data){
            curr=head2->next;
            ptr->next=head2;
            ptr=head2;
            head2=curr;
        }
        else{
            curr=head1->next;
            ptr->next=head1;
            ptr=head1;
            head1=curr;
        }
    }
    if(head1==NULL){
        ptr->next=head2;
    }
    else{
        ptr->next=head1;
    }
    return FinalHead;
}