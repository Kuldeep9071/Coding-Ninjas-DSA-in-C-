#include<bits/stdc++.h>
using namespace std;
#include "BinaryTreeClass.C++"

int height(BinaryTreeNode<int>* root){
	if(root==NULL) return 0;
	return 1+max(height(root->left),height(root->right));
}
bool isBalanced(BinaryTreeNode<int> *root) {
	if(root==NULL) return true;
	if(height(root->left)-height(root->right)>1 || height(root->right)-height(root->left)>1) return false;
	isBalanced(root->left);
	isBalanced(root->right);
}

/*
Problem statement
Given a binary tree, check if it is balanced. Return true
 if given binary tree is balanced, false otherwise.

Balanced Binary Tree:
A empty binary tree or binary tree with zero nodes is always balanced. 
For a non empty binary tree to be balanced, following conditions must be met:
1. The left and right subtrees must be balanced.
2. |hL - hR| <= 1, where hL is the height or depth of left subtree and
 hR is the height or depth of right subtree.    


Detailed explanation ( Input/output format, Notes, Images )

Constraints

Time Limit: 1 second
Sample Input 1 :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1 :
false
Sample Input 2 :
1 2 3 -1 -1 -1 -1
Sample Output 2 :
true
*/