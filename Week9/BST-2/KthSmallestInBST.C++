#include<bits/stdc++.h>
using namespace std;
#include "BinaryTreeClass.C++"

void inorder(BinaryTreeNode<int> *root, vector<int> &ans){
    if(root==NULL) return;
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}
int findNode(BinaryTreeNode<int>* root, int k) {
	vector<int> ans;
	inorder(root,ans);
	int i=0;
	if(k<0) return INT_MIN;
	while(i<ans.size() && i!=k-1){
		i++;
	}
	if(i<ans.size()) return ans[i];
	else return INT_MIN;
}