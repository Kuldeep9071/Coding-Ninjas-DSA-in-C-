#include<bits/stdc++.h>
using namespace std;
#include "BinaryTreeClass.C++"

void inorder(BinaryTreeNode<int> *root, vector<int> &ans) {
    if (root == NULL) return;
    if (root->left != NULL) inorder(root->left, ans);
    ans.push_back(root->data);
    if (root->right != NULL) inorder(root->right, ans);
}
bool pairSumBst(BinaryTreeNode<int> *root, int k){
    vector<int> ans;
    inorder(root, ans);
    int i=0;
    int j=ans.size()-1;
    while(i<j){
        if (ans.at(i)+ans.at(j) == k) {
            return true;
        } 
        else if (ans.at(i)+ans.at(j) < k) {
            i++;
        } 
        else {
            j--;
        }
    }
    return false;
}