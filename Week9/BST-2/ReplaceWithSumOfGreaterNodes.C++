#include<bits/stdc++.h>
using namespace std;
#include "BinaryTreeClass.C++"

void inorder(BinaryTreeNode<int> *root, vector<BinaryTreeNode<int>*> &ans){
    if(root==NULL) return;
    inorder(root->left,ans);
    ans.push_back(root);
    inorder(root->right,ans);
}

void replaceWithLargerNodesSum(BinaryTreeNode<int> *root) {
    vector<BinaryTreeNode<int>*> ans;
    inorder(root,ans);
    int n=ans.size();
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=ans[j]->data;
        }
        ans[i]->data=sum;
    }
}

/*
Problem statement
Given a binary search tree, you have to replace each node's data with the sum of all nodes which are greater or equal than it. You need to include the current node's data also.

That is, if in given BST there is a node with data 5, you need to replace it with sum of its data (i.e. 5) and all nodes whose data is greater than or equal to 5.

Note: You don't need to return or print, just change the data of each node.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
Time Limit: 1 second
Sample Input 1 :
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
Sample Output 1 :
18 
36 10 
38 31 
25
*/