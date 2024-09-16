#include<bits/stdc++.h>
using namespace std;
#include "Tree.C++"
#include<queue>
#include<limits.h>

TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    if(root==NULL){
        return root;
    }

    int max=INT_MIN;
    int Secmax=INT_MIN;
    TreeNode<int>* maxNode=NULL;
    TreeNode<int>* ansNode=NULL;
    queue<TreeNode<int>*> Q;
    Q.push(root);

    while(!Q.empty()){

        TreeNode<int>* A=Q.front();
        Q.pop();
        if(A->data>max){
            ansNode=maxNode;
            maxNode=A;
            Secmax=max;
            max=A->data;
        }
        for(int i=0;i<A->children.size();i++){
            if(A->children[i]->data>max){
                ansNode=maxNode;
                maxNode=A->children[i];
                Secmax=max;
                max=A->children[i]->data;
            }
            else if(A->children[i]->data<max && A->children[i]->data>Secmax ){
                ansNode=A->children[i];
                Secmax=A->children[i]->data;
            }
            Q.push(A->children[i]);
        }
    }
    return ansNode;
}