#include<bits/stdc++.h>
using namespace std;
#include"LinkedListClass.C++"

int findNode(Node *head, int n){
    if(head==NULL){
        return-1;
    }
    Node* temp=head;
    int ans=0;
    while(temp!=NULL){
        if(temp->data==n){
            return ans;
        }
        else{
            ans++;
            temp=temp->next;
        }
    }
    return -1;
}