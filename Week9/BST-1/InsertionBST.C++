#include<bits/stdc++.h>
using namespace std;
#include "BinaryTreeClass.C++"

BinaryTreeNode<int>* insertionInBST(BinaryTreeNode<int>* root, int val){
    if(root==NULL){
        return new BinaryTreeNode<int>(val);
    }
    if(val>root->data){
        BinaryTreeNode<int>* P=insertionInBST(root->right, val);
        root->right=P;
        return root;
    }
    if(val<root->data){
        BinaryTreeNode<int>* P=insertionInBST(root->left, val);
        root->left=P;
        return root;
    }
}