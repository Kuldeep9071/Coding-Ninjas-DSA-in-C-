#include<bits/stdc++.h>
using namespace std;
#include "BinaryTreeClass.C++"

#include<bits/stdc++.h>
void inOrder(BinaryTreeNode<int>* root,vector<int> &ans){
	if(root==NULL) return;
	if(root->left!=NULL) inOrder(root->left,ans);
	ans.push_back(root->data);
	if(root->right!=NULL) inOrder(root->right,ans);
}
void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) {
	vector<int> ans;
	inOrder(root,ans);
	int i=0;
	while(i<ans.size()){
		if(ans[i]>k2) break;
		else if(ans[i]<k1);
		else cout<<ans[i]<<" ";
		i++;
	}
}