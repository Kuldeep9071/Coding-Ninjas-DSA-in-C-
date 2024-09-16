#include<bits/stdc++.h>
using namespace std;
#include "BinaryTreeClass.C++"

BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int> *root) {
    if(root==NULL) return NULL;
	if(root->left==NULL && root->right==NULL){
		BinaryTreeNode<int>* a=root;
		delete a;
		return NULL;
	}
	if(root->left!=NULL){
		if(root->left->left==NULL && root->left->right==NULL){
			BinaryTreeNode<int>* a=root->left;
			root->left=NULL;
			delete a;
		}
	}
	if(root->right!=NULL){
		if(root->right->right==NULL && root->right->left==NULL){
			BinaryTreeNode<int>* a=root->right;
			root->right=NULL;
			delete a;
		}
	}
	removeLeafNodes(root->left);
	removeLeafNodes(root->right);
	return root;
}

