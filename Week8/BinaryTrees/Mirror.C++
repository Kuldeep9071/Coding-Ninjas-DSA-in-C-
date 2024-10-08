#include<bits/stdc++.h>
using namespace std;
#include "BinaryTreeClass.C++"

void mirrorBinaryTree(BinaryTreeNode<int>* root) {
    if(root==NULL){
		return;
	}
	BinaryTreeNode<int>* A=root->left;
	root->left=root->right;
	root->right=A;

	 mirrorBinaryTree(root->left);
	 mirrorBinaryTree(root->right);	
}

/*
Problem statement
For a given Binary Tree of type integer, update it with its corresponding mirror image.

Examples:

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
Sample Input 1:
1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1
Sample Output 1:
1 
3 2 
7 6 5 4
Sample Input 2:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 2:
5 
6 10 
3 2 
9
*/