#include<bits/stdc++.h>
using namespace std;
#include "BinaryTreeClass.C++"

bool getpath(BinaryTreeNode<int> *root , int data, vector<int> &ans){
	if(root==NULL) return false;
	ans.push_back(root->data);
	if(root->data==data) return true;
	else if(root->data>data) getpath(root->left,data,ans);
	else getpath(root->right,data,ans);
}
vector<int>* getPath(BinaryTreeNode<int> *root , int data) {
	vector<int> ans;
	bool b=getpath(root,data,ans);
	if(b==1){
		int j=ans.size()-1;
		while(j>=0){
			cout<<ans[j]<<" ";
			j--;
		}
	}
	return &ans;
}

/*
Problem statement
Given a BST and an integer k. Find and return the path from the node with data k and 
root (if a node with data k is present in given BST) in a list. Return empty list otherwise.

Note: Assume that BST contains all unique elements.

Detailed explanation ( Input/output format, Notes)
Constraints:

Time Limit: 1 second   
Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
2


Sample Output 1:
2 5 8
*/