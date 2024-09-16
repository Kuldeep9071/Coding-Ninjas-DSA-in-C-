#include<bits/stdc++.h>
using namespace std;
#include "BinaryTreeClass.C++"

bool searchInBST(BinaryTreeNode<int> *root , int k) {
	if(root==NULL) return false;
	if(root->data==k) return true;
	if(root->data>k) searchInBST(root->left,  k);
	else searchInBST(root->right,  k);
}