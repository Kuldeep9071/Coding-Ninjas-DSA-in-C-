#include<bits/stdc++.h>
using namespace std;
#include "Tree.C++"

#include<queue>
#include<limits.h>
TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x) {
    if(root==NULL){
        return  root;
    }
    queue<TreeNode<int>*> Q;
    Q.push(root);
    TreeNode<int>* ansNode=NULL;
    int mindiff=INT_MAX;
    while(!Q.empty()){
        TreeNode<int>* A=Q.front();
        Q.pop();
        if(root->data>x && root->data-x<mindiff){
                mindiff=root->data-x;
                ansNode=root;
            }
        for(int i=0;i<A->children.size();i++){
            if(A->children[i]->data>x && A->children[i]->data-x<mindiff){
                mindiff=A->children[i]->data-x;
                ansNode=A->children[i];
            }
            Q.push(A->children[i]);
        }
    }
    return ansNode;  
}
/*
Problem statement

Given a generic tree and an integer n. Find and return the node with next 
larger element in the tree i.e. find a node with value just greater than n.

Note: Return NULL if no node is present with the value greater than n.

Detailed explanation ( Input/output format, Notes)

Constraints:

Time Limit: 1 sec
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
18
Sample Output 1 :
20
Sample Input 2 :
10 3 20 30 40 2 40 50 0 0 0 0 
21
Sample Output 2:
30
*/