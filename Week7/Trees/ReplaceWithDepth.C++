#include<bits/stdc++.h>
using namespace std;
#include "Tree.C++"

void helper(TreeNode<int>* root,int depth){
    root->data=depth;
    for(int i=0;i<root->children.size();i++){
        helper(root->children[i],depth+1);
    }
}
void replaceWithDepthValue(TreeNode<int>* root) {
    if (root == NULL) {
        return;
    }
    helper(root,0);
}

/*
Problem statement
You are given a generic tree. You have to replace each node with its depth value.
You just have to update the data of each node, there is no need to return or print anything.

Detailed explanation ( Input/output format, Notes)

Constraints:
Time Limit: 1 sec
Sample Input 1:
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1:
0 
1 1 1 
2 2
*/