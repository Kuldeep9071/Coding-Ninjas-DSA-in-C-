#include<bits/stdc++.h>
using namespace std;
#include "Tree.C++"

#include<queue>
bool isPresent(TreeNode<int>* root, int x) {
    if(root==NULL){
        return false;
    }
    queue<TreeNode<int>*> a;
    a.push(root);
    if(root->data==x){
        return true;
    }
    while(!a.empty()){
        TreeNode<int>* A=a.front();
        a.pop();
        for(int i=0;i<A->children.size();i++){
            if(A->children[i]->data==x){
                return true;
            }
            a.push(A->children[i]);
        }
    }
    return false;   
}

/*
Problem statement
Given a generic tree and an integer x, check if x is present in the 
given tree or not. Return true if x is present, return false otherwise.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
Time Limit: 1 sec
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0
40 
Sample Output 1 :
true
Sample Input 2 :
10 3 20 30 40 2 40 50 0 0 0 0
4 
Sample Output 2:
false

*/