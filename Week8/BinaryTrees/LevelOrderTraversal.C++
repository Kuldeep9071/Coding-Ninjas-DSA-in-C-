#include<bits/stdc++.h>
using namespace std;
#include "BinaryTreeClass.C++"

#include<math.h>

void printLevelWise(BinaryTreeNode<int> *root) {
	if(root==NULL){
		return;
	}
	queue<BinaryTreeNode<int>*> Q;
	Q.push(root);
	Q.push(NULL);
	cout<<root->data<<endl;
	while(!Q.empty()){
		BinaryTreeNode<int>* A=Q.front();
		Q.pop();
		if(A==NULL){
			if(Q.empty()){
				break;
			}
			Q.push(NULL);
			cout<<endl;
		}
		else{
			if(A->left!=NULL){
			cout<<A->left->data<<" ";
			Q.push(A->left);
			}
			if( A->right!=NULL){
			cout<<A->right->data<<" ";
			Q.push(A->right);
			}
		}
	}
}

/*
Problem statement
For a given a Binary Tree of type integer, print it in a level order fashion 
where each level will be printed on a new line. Elements on every level 
will be printed in a linear fashion and a single space will separate them.

Example:
alt txt

For the above-depicted tree, when printed in a level order fashion, 
the output would look like:

10
20 30 
40 50 60

Where each new line denotes the level in the tree.

Detailed explanation ( Input/output format, Notes)

Constraints:
1 <= N <= 10^5
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
Sample Input 1:
10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1 
Sample Output 1:
10 
20 30 
40 50 60 
Sample Input 2:
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
Sample Output 2:
8 
3 10 
1 6 14 
4 7 13 

*/