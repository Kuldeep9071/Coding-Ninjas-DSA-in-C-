#include<bits/stdc++.h>
using namespace std;
#include "Tree.C++"

int getHeight(TreeNode<int>* root) {
    if(root==NULL){
        return 0;
    }
    int max=0;
    for(int i=0;i<root->children.size();i++){
        int x=getHeight(root->children[i]);
        if(x>max){
            max=(x);
        }
    }
    return 1+max;
}
/*
Problem statement
Given a generic tree, find and return the height of given tree. The height of a tree 
is defined as the longest distance from root node to any of the leaf node. 
Assume the height of a tree with a single node is 1.

Detailed explanation ( Input/output format, Notes)
Constraints:
Time Limit: 1 sec
Sample Input 1:
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1:
3*/