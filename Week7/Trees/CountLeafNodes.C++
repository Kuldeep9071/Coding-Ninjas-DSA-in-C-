#include<bits/stdc++.h>
using namespace std;
#include "Tree.C++"

int getLeafNodeCount(TreeNode<int>* root) {
    if(root==NULL){
        return 0;
    }
    if(root->children.size()==0){
        return 1;
    }
    int ans=0;
    for(int i=0;i<root->children.size();i++){
        ans+=getLeafNodeCount(root->children[i]);
    }
    return ans;
}
