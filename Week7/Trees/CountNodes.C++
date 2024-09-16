#include<bits/stdc++.h>
using namespace std;
#include "Tree.C++"

int getLargeNodeCount(TreeNode<int>* root, int x) {
    if(root==NULL){
        return 0;
    }
    int ans=0;
    queue<TreeNode<int>*> a;
    a.push(root);
    if(root->data>x){
        ans++;
    }
    while(!a.empty()){
        TreeNode<int>* A=a.front();
        a.pop();
        for(int i=0;i<A->children.size();i++){
            if(A->children[i]->data>x){
                ans++;
            }
            a.push(A->children[i]);
        }
    }
    return ans;   
}

/*
Given a tree and an integer x, find and return the number of nodes
 which contains data greater than x.

Detailed explanation ( Input/output format, Notes)

Constraints:
Time Limit: 1 sec
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0
35 
Sample Output 1 :
3
Sample Input 2 :
10 3 20 30 40 2 40 50 0 0 0 0
10 
Sample Output 2:
5
*/