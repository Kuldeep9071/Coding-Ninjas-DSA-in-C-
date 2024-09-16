#include<bits/stdc++.h>
using namespace std;
#include "BinaryTreeClass.C++"

bool areSiblings(BinaryTreeNode<int> *root, int p, int q) {
    if(root == NULL) return false;
    if(root -> left and root -> right) {
        int left = root -> left -> data;
        int right = root -> right -> data;
        
        if((left == p and right == q) or (left == q or right == p)) {
            return true;
        }   
    } 
    else return false;
    return areSiblings(root -> left, p, q) or areSiblings(root -> right, p, q);
}

int getLevel(BinaryTreeNode<int> *root, int data, int count) {
    if(root == NULL) return 0;
    else if(root -> data == data) return count;   
    int left = getLevel(root -> left, data, count + 1);
    if(left) return left;
    else return getLevel(root -> right, data, count + 1);
}
bool isCousin(BinaryTreeNode<int> *root, int p, int q) {
	if((getLevel(root, p, 1) == getLevel(root, q, 1)) and !areSiblings(root, p, q)) return true;
    else return false;
}

/*
Problem statement
Given the binary Tree and two nodes say ‘p’ and ‘q’. Determine whether the 
two nodes are cousins of each other or not. Two nodes are said to be cousins
of each other if they are at same level of the Binary Tree and have different parents.

Do it in O(n).

Detailed explanation ( Input/output format, Notes)

Constraints :
1 <= N <= 10^5

Sample Input :
5 6 10 2 3 4 -1 -1 -1 -1 9 -1 -1 -1 -1
2
4
Sample Output :
true

*/