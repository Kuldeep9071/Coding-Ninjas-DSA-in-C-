#include<bits/stdc++.h>
using namespace std;
#include "BinaryTreeClass.C++"
#include<limits.h>

pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
	pair<int,int> ans;
	if(root==NULL){
		ans.first=INT_MAX;
		ans.second=INT_MIN;
		return ans;
	}
	pair<int,int> MinMaxL=getMinAndMax(root->left);
	pair<int,int> MinMaxR=getMinAndMax(root->right);
	ans.first=min(root->data,min(MinMaxL.first,MinMaxR.first));
	ans.second=max(root->data,max(MinMaxL.second,MinMaxR.second));
	return ans;
}