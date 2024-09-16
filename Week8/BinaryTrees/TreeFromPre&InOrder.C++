#include<bits/stdc++.h>
using namespace std;
#include "BinaryTreeClass.C++"

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    if(preLength==0){
		return NULL;
	}
	BinaryTreeNode<int>* root=new BinaryTreeNode<int>(preorder[0]);
	int i=0;
	while(inorder[i]!=preorder[0]){
		i++;
	}
	root->left=buildTree(preorder+1, i,inorder,i);
	root->right=buildTree(preorder+i+1,inLength-i-1,inorder+i+1,inLength-i-1);
	return root;
}