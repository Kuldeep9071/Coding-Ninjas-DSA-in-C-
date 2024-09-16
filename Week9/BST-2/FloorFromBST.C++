#include<bits/stdc++.h>
using namespace std;
#include "BinaryTreeClass.C++"

#include<bits/stdc++.h>
void inorder(BinaryTreeNode<int> *node, vector<int>& ans){
    if(node==NULL) return;
    inorder(node->left,ans);
    ans.push_back(node->data);
    inorder(node->right,ans);
}
int Floor(BinaryTreeNode<int> *node, int input){
	vector<int> ans;
    inorder(node,ans);
    int i=0;
    while(ans[i]<input){
        i++;
    }
    if(ans[i]==input) return ans[i];
    else return ans[i-1];
}
/*
Problem statement
Given a binary search tree and an integer.Find the floor value of a key in a BST.

(If k lies in BST then is floor equal to k,else floor is equal to previous greater value) 

NOTE: k would never be less than the minimum element of tree.

Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
4
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
Sample Output 1:
2
Sample Input 2:
7
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
Sample Output 2:
6
*/