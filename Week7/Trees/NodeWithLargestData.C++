#include<bits/stdc++.h>
using namespace std;
#include "Tree.C++"

#include<queue>
TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    if(root==NULL){
        return root;
    }
    TreeNode<int>* maxNode=root;
    queue<TreeNode<int>*> a;
    a.push(root);
    while(!a.empty()){
        TreeNode<int>* A=a.front();
        a.pop();
        for(int i=0;i<A->children.size();i++){
            if(A->children[i]->data>maxNode->data){
                maxNode=A->children[i];
            }
            a.push(A->children[i]);
        }
    } 
    return maxNode;
}

/*
Problem statement
Given a generic tree, find and return the node with maximum data.
 You need to return the node which is having maximum data.

Return null if tree is empty.

Detailed explanation ( Input/output format, Notes)
Constraints:

Time Limit: 1 sec
Sample Input 1:
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1:
50
*/