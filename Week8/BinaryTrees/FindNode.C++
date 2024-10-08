#include<bits/stdc++.h>
using namespace std;
#include "BinaryTreeClass.C++"

bool isNodePresent(BinaryTreeNode<int> *root, int x) {
    if(root==NULL){
        return false;
    }
    queue<BinaryTreeNode<int>*> Q;
    Q.push(root);
    while(!Q.empty()){
        BinaryTreeNode<int>* A=Q.front();
        Q.pop();
        if(A->data==x){
            return true;
        }
        if(A->left==NULL&&A->right==NULL){
            return false;
        }
        if(A->left!=NULL ){
            if(A->left->data==x){
                return true;
            }
            else{
                Q.push(A->left);
            }  
        }
        if(A->right!=NULL ){
            if(A->right->data==x){
                return true;
            }
            else{
                Q.push(A->right);
            }
        }
    }
}

/*
Problem statement
For a given Binary Tree of type integer and a number X, find whether 
a node exists in the tree with data X or not.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= N <= 10^5

Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec.
Sample Input 1:
8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
7
Sample Output 1:
true
Explanation For Output 1:
Clearly, we can see that 7 is present in the tree. So, the output will be true.
Sample Input 2:
2 3 4 -1 -1 -1 -1
10
Sample Output 2:
false
*/