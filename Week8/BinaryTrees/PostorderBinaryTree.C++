#include<bits/stdc++.h>
using namespace std;
#include "BinaryTreeClass.C++"

void postOrder(BinaryTreeNode<int> *root) {
	if(root==NULL) return;
	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data<<" ";
}