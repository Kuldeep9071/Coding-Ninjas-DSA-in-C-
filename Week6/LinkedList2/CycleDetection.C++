#include<bits/stdc++.h>
using namespace std;
#include"LinkedListClass.C++"

bool detectCycle(Node *head){
    if(head==NULL || head->next==NULL){
        return false;
    }

    Node* slow=head;
    Node* fast=head->next->next;
    while(fast!=NULL && fast->next!=NULL){
        if(fast==slow){
            return true;
        }
        fast=fast->next->next;
        slow=slow->next;
    }
    return false;
}