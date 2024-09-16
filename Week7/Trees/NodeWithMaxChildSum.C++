#include<bits/stdc++.h>
using namespace std;
#include "Tree.C++"

#include<queue>
TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    if(root==NULL){
        return root;
    }
    int max=root->data;
    TreeNode<int>* maxNode=root;
    queue<TreeNode<int>*> Q;
    Q.push(root);
    while(!Q.empty()){
        TreeNode<int>* A=Q.front();
        Q.pop();
        int sum=0;
        for(int i=0;i<A->children.size();i++){
            Q.push(A->children[i]);
            sum+=A->children[i]->data;
        }
        if(sum>max){
            max=sum;
            maxNode=A;
        }
    }
    return maxNode;
}
/*
Problem statement:

Given a generic tree, find and return the node for which sum of its data 
and data of all its child nodes is maximum. In the sum, data of the node 
and data of its immediate child nodes has to be taken.

Detailed explanation ( Input/output format, Notes)

Constraints:
Time Limit: 1 sec
0 < Node's val <= 10^5
Sample Input 1 :
5 3 1 2 3 1 15 2 4 5 1 6 0 0 0 0


Sample Output 1 :
1
*/