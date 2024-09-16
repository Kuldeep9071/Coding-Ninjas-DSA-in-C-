#include<bits/stdc++.h>
using namespace std;
#include "BinaryTreeClass.C++"


void zigZagOrder(BinaryTreeNode<int> *root) {
    if(root==NULL){
		return;
	}
	bool b=1;
	stack<BinaryTreeNode<int>*> CurrLevel;
	stack<BinaryTreeNode<int>*> NextLevel;
	CurrLevel.push(root);

	while(!CurrLevel.empty()){
		BinaryTreeNode<int>* X=CurrLevel.top();
		CurrLevel.pop();
		cout<<X->data<<" ";
		if(b==1){
			if(X->left!=NULL) NextLevel.push(X->left);
			if(X->right!=NULL) NextLevel.push(X->right);
		}
		else{
			if(X->right!=NULL) NextLevel.push(X->right);
			if(X->left!=NULL) NextLevel.push(X->left);
		}
		if(CurrLevel.empty()){
			b=!b;
			swap(CurrLevel,NextLevel);
			cout<<endl;
		}
	}
}