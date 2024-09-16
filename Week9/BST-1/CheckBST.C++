#include<bits/stdc++.h>
using namespace std;
#include "BinaryTreeClass.C++"

#include<bits/stdc++.h>
int minVal(BinaryTreeNode<int> *root){
	if(root==NULL) return -1;
	if(root->left==NULL) return root->data;
	minVal(root->left);
}
int maxVal(BinaryTreeNode<int> *root){
	if(root==NULL) return -1;
	if(root->right==NULL) return root->data;
	maxVal(root->right);
}

bool isBST(BinaryTreeNode<int> *root) {
	if(root==NULL) return true;
	if(root->right!=NULL || root->left!=NULL){
		if(root->left==NULL){
			if(root->data<=minVal(root->right)) isBST(root->right);
			else return false;
		}
		else if(root->right==NULL){
			if(root->data>maxVal(root->left)) isBST(root->left);
			else return false;
		}
		else{
			if(root->data>maxVal(root->left)) isBST(root->left);
			else return false;
			if(root->data<=minVal(root->right)) isBST(root->right);
			else return false;
		}
	}
	else{
		return true;
	}
}