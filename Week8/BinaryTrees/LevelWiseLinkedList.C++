#include<bits/stdc++.h>
using namespace std;
#include "BinaryTreeClass.C++"
#include "LinkedListClass.C++"
#include<queue>
#include<limits.h>

vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
	vector<Node<int>*> ans;
    if(root==NULL){
		return ans;
	}
	queue<BinaryTreeNode<int>*> Q;
	Q.push(root);
	Q.push(NULL);
	Node<int>* R=new Node<int>(root->data);
	ans.push_back(R);
	Node<int>* P=NULL;	
	Node<int>* tail=P;
	while(!Q.empty()){		
		BinaryTreeNode<int>* A=Q.front();
		Q.pop();
		if(A==NULL){
			if(Q.empty()){
				return ans;
			}
			else{
				Q.push(NULL);
				Node<int>* K=P;
				P=NULL;
				tail=NULL;
				ans.push_back(K);
			}
		}
		else{
			if(A->left!=NULL){
				Node<int>* X=new Node<int>(A->left->data);
				Q.push(A->left);
				if(tail!=NULL){
					tail->next=X;
					tail=tail->next;
				}
				else{
					tail=X;
					P=tail;
				}
			}
			if(A->right!=NULL){
				Node<int>* X=new Node<int>(A->right->data);
				Q.push(A->right);
				if(tail!=NULL){
					tail->next=X;
					tail=tail->next;
				}
				else{
					tail=X;
					P=tail;
				}
			}
		}
	}
}

/*
Problem statement
Given a binary tree, write code to create a separate linked list for each level.
 You need to return the array which contains head of each level linked list.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
Time Limit: 1 second
Sample Input 1:
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1:
5 
6 10 
2 3 
9
*/