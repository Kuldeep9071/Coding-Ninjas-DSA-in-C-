#include<bits/stdc++.h>
using namespace std;

template <typename T>
	class Node {
		public:
    	T data;
    	Node<T> *next;
        Node(){
            this->data = 0;
            this->next = NULL;
        }
    	Node(T data){
        	this->data=data;
        	this->next=NULL;
    	}
        Node(int data, Node* next){
            this->data = data;
            this->next = next;
        }
	};