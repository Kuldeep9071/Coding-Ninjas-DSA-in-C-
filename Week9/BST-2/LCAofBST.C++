#include<bits/stdc++.h>
using namespace std;
#include "BinaryTreeClass.C++"

bool getPath(BinaryTreeNode<int>* root , int val,vector<int> &path){
	if(root==NULL) return 0;
    if(val==root->data){
        path.push_back(root->data);
        return 1;
    }
    else if(val>root->data){
        path.push_back(root->data);
        getPath(root->right,val,path);
    }
    else{
        path.push_back(root->data);
        getPath(root->left,val,path);
    }
}
int getLCA(BinaryTreeNode<int>* root , int val1 , int val2){
    vector<int> path1;
    vector<int> path2;
    bool b1=getPath(root,val1,path1);
    bool b2=getPath(root,val2,path2);
    if(b1==0 && b2==0) return -1;
    else if(b2==0) return val1;
    else if(b1==0) return val2;
    else{
        int i=path1.size()-1;
        int j=path2.size()-1;
        for(int k=0;k<i;k++){
            if(path1[k]==val2) return val2;
        }
        for(int k=0;k<j;k++){
            if(path2[k]==val1) return val1;
        }
        while(path1[i]!=path2[j]){
            i--;
            j--;
        }
        return path1[i];
    }
}

/*
Problem statement
Given a binary search tree and data of two nodes, find 'LCA' (Lowest Common Ancestor) 
of the given two nodes in the BST.

LCA of two nodes A and B is the lowest or deepest node which has both A and B as its descendants. 

Example:
In this example, the green coloured node is the LCA to A and B.
Alt Text

Note:
It is defined that each node is a descendant to itself, so, if there are two nodes X and Y
 and X has a direct connection from Y, then Y is the lowest common ancestor.

Example:

Note:

1. If out of 2 nodes only one node is present, return that node. 
2. If both are not present, return -1.
3. all the node data will be unique.


Detailed explanation ( Input/output format, Notes, Images )

Constraints:

Time Limit: 1 second

Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
2 10
Sample Output 1:
8
Sample Input 2:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
2 6
Sample Output 2:
5
Sample Input 3:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
12 78
Sample Output 3:
-1
*/