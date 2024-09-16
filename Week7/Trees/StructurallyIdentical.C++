#include<bits/stdc++.h>
using namespace std;
#include "Tree.C++"

bool areIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    if(root1==NULL && root2==NULL){
        return true;
    }
    else if((root1==NULL && root2!=NULL) || (root1!=NULL && root2==NULL)){
        return false;
    }
    if(root1->data!=root2->data || root1->children.size()!=root2->children.size()){
        return false;
    }
    else if(root1->data==root2->data && root1->children.size()==0 && root2->children.size()==0){
        return true;
    }
    for(int i=0;i<root1->children.size();i++){
        return areIdentical(root1->children[i], root2->children[i]);
    }
}

/*
Problem statement
Given two generic trees, return true if they are structurally identical. Otherwise return false.

Structural Identical
If the two given trees are made of nodes with the same values and the 
nodes are arranged in the same way, then the trees are called identical.  

Detailed explanation ( Input/output format, Notes)

Constraints:
Time Limit: 1 sec
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
10 3 20 30 40 2 40 50 0 0 0 0
Sample Output 1 :
true
Sample Input 2 :
10 3 20 30 40 2 40 50 0 0 0 0 
10 3 2 30 40 2 40 50 0 0 0 0
Sample Output 2:
false
*/