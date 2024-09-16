#include<bits/stdc++.h>
using namespace std;
#include "BinaryTreeClass.C++"

BinaryTreeNode<int>* deleteNode(BinaryTreeNode<int>* root, int key) {
    if(root==NULL){
        return NULL ;
    }
    if(root->data==key && root->left==NULL && root->right==NULL){
        BinaryTreeNode<int>* X=root;
        delete X;
        return NULL;
    }
    else if(root->data==key && (root->left!=NULL || root->right!=NULL)){
        BinaryTreeNode<int>* X=root;
        if(root->right==NULL){
            root=root->left;
        }
        else if(root->left==NULL){
            root=root->right;
        }
        else{
            BinaryTreeNode<int>* A=root->left;
            root=root->right;
            BinaryTreeNode<int>* Y=root;
            while(Y->left!=NULL)           {
                Y=Y->left;
            }
            Y->left=A;
        }
        delete X;
        return root;
    }
    else if(root->data>key){
        BinaryTreeNode<int>* X=NULL;
        if (root->left!=NULL)  X=deleteNode(root->left, key);
        root->left=X;
        return root;
    }
    else if(root->data<key){
        BinaryTreeNode<int>* X=NULL;
        if (root->right!=NULL) X= deleteNode(root->right, key);
        root->right=X;
        return root;
    }
}
