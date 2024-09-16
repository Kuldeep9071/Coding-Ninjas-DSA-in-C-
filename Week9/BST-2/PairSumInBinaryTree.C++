#include<bits/stdc++.h>
using namespace std;
#include "BinaryTreeClass.C++"

void inorder(BinaryTreeNode<int> *root, vector<int> &ans) {
    if (root == NULL) return;
    if (root->left != NULL) inorder(root->left, ans);
    ans.push_back(root->data);
    if (root->right != NULL) inorder(root->right, ans);
}

void pairSum(BinaryTreeNode<int> *root, int sum) {
    if (root == NULL) return;

    vector<int> ans;
    inorder(root, ans);
    sort(ans.begin(), ans.end());

    int i = 0;
    int j = ans.size() - 1;

    while (i<j) { 
        int current_sum = ans[i] + ans[j];
        if (current_sum == sum) {
            cout << min(ans[i], ans[j]) << " " << max(ans[i], ans[j]) << endl;
            i++;
            j--;
        } 
        else if (current_sum < sum) i++;
        else j--;
    }
}