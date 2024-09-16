#include<bits/stdc++.h>
using namespace std;
#include "BinaryTreeClass.C++"

BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    if(inLength==0){
		return NULL;
	}
	BinaryTreeNode<int>* root=new BinaryTreeNode<int>(postorder[postLength-1]);
	int i=0;
	while(inorder[i]!=postorder[postLength-1]){
		i++;
	}
	root->left=buildTree(postorder,i,inorder,i);
	root->right=buildTree(postorder+i,postLength-i-1,inorder+i+1,inLength-i-1);
	return root;
}