#include<bits/stdc++.h>
using namespace std;
#include "BinaryTreeClass.C++"

vector<int>* longestPath(BinaryTreeNode<int>* root) {
	if(root == NULL) {
        vector<int> *temp = new vector<int>();
        return temp;
    }
    
    vector<int> *left = longestPath(root -> left);
    vector<int> *right = longestPath(root -> right);
    
    if(left -> size() > right -> size()) {
        left -> push_back(root -> data);
        return left;
    } else {
        right -> push_back(root -> data);
        return right;
    }
}

/*
Problem statement
Given a binary tree, return the longest path from leaf to root. Longest means,
 a path which contain maximum number of nodes from leaf to root.

Detailed explanation ( Input/output format, Notes, Images )

Sample Input 1 :
 5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1

Sample Output 1 :
9
3
6
5

 */