#include<bits/stdc++.h>
using namespace std;
#include "LinkedList.C++"

class Stack {
	Node *head;
    int size;
    public:
    Stack() {
        head=NULL;
        size=0;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        if(head==NULL){
            return true;
        }
        return false;
    }

    void push(int element) {
        Node *a=new Node(element);
        a->next=head;
        head=a;
        size++;
    }

    int pop() {
        if(head==NULL){
            return -1;
        }
        int x=head->data;
        Node * a=head;
        head=head->next;
        delete a;
        size--;
        return x;
    }

    int top() {
        if(head==NULL){
            return -1;
        }
        return head->data;
    }
};