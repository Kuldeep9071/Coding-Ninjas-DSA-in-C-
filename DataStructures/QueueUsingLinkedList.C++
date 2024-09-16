#include<bits/stdc++.h>
using namespace std;
#include "LinkedList.C++"

class Queue {
	Node* head;
	Node* tail;
	int size;
   public:
    Queue() {
		head=NULL;
		tail=NULL;
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

    void enqueue(int data) {		
		Node* a=new Node(data);
		if(tail==NULL){
			head=a;
			tail=a;
		}
		tail->next=a;
		tail=tail->next;
		size++;
	}

    int dequeue() {
		if(head==NULL){
			return -1;
		}
        Node* a=head;
		int ans=head->data;
		head=head->next;
		delete a;
		size--;
		return ans;
    }

    int front() {
        if(head==NULL){
			return -1;
		}
		return head->data;
    }
};