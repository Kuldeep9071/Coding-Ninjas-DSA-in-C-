#include<bits/stdc++.h>
using namespace std;
#include "BinaryTreeClass.C++"

pair<int,pair<int,int>> HeightMinMax(BinaryTreeNode<int> *root){
    if(root==NULL) return {0,{INT_MAX,INT_MIN}};
    pair<int,pair<int,int>> R=HeightMinMax(root->right);
    pair<int,pair<int,int>> L=HeightMinMax(root->left);
    if(root->data>(L.second.second) && root->data<R.second.first){
        return{1+(max(R.first,L.first)),{min(root->data,min(R.second.first,L.second.first)),max(root->data,max(R.second.second,L.second.second))}};
    }
    else{
        return {(max(L.first,R.first)),{INT_MIN,INT_MAX}};
    }
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
    pair<int,pair<int,int>> ans=HeightMinMax(root);
    return ans.first;
}