#include<bits/stdc++.h>
using namespace std;
#include"LinkedListClass.C++"

Node* InsertNodeHelper(Node* Return,Node *head, int pos, Node* newNode){
	if(head==NULL || pos==0){
        Node* a=head;
        newNode->next=a;
        head=newNode;
        return head;
    }
    if(pos==1){
        Node* a=head->next;
        head->next=newNode;
        newNode->next=a;
        return head;
    }
    if(pos==2){
        Node* a=head->next->next;
        head->next->next=newNode;
        newNode->next=a;
        return Return;
    }
    return InsertNodeHelper(Return,head->next,pos-1,newNode);
}

Node* InsertNode(Node *head, int pos, Node* newNode){
	return InsertNodeHelper(head, head, pos, newNode);
}