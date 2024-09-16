#include<bits/stdc++.h>
using namespace std;
#include "BinaryTreeClass.C++"

void helper(BinaryTreeNode<int> * root,vector<int> &A){
    if(root==NULL){
        return;
    }   
    A.push_back(root->data);
    helper(root->left,A);
    helper(root->right,A);
}

vector<int> preOrder(BinaryTreeNode<int> * root){
    vector<int> A;
    helper(root, A);
    return A;
}