#include<bits/stdc++.h>
using namespace std;
#include "Tree.C++"


int sumOfNodes(TreeNode<int>* root) {
    int ans=root->data;
    for(int i=0;i<root->children.size();i++){
        ans+=sumOfNodes(root->children[i]);
    }
    return ans;
}