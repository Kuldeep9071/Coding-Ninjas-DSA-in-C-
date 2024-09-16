#include<bits/stdc++.h>
using namespace std;
#include "BinaryTreeClass.C++"

int minVal(BinaryTreeNode<int>* root){
	if(root==NULL) return -1;
	if(root->left==NULL) return root->data;
	minVal(root->left);
}

// OR

int minVal(BinaryTreeNode<int>* root){
	if(root==NULL) return -1;
	while(root->left!=nullptr){
		root=root->left;
	}
	return root->data;
}


