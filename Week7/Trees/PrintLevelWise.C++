#include<bits/stdc++.h>
using namespace std;
#include "Tree.C++"

#include<queue>
void printLevelWise(TreeNode<int>* root) {
   if(root==NULL){
       return;
   }
   queue<TreeNode<int>*> Pending;
   Pending.push(root);
   while(!Pending.empty()){
       TreeNode<int>* a=Pending.front();
       cout<<a->data<<":";
       Pending.pop();
       int i=0;
       while(i<a->children.size()){
            if(i==a->children.size()-1){
                cout<<a->children[i]->data;
                Pending.push(a->children[i]);
                i++;
            }
            else{
                cout<<a->children[i]->data<<",";
                Pending.push(a->children[i]);
                i++;
            }
        }
        cout<<endl;
   }
}

/*
Problem statement
Given a generic tree, print the input tree in level wise order.

For printing a node with data N, you need to follow the exact format -

N:x1,x2,x3,...,xn
where, N is data of any node present in the generic tree. x1, x2, x3, ...., xn 
are the children of node N. Note that there is no space in between.

You need to print all nodes in the level order form in different lines.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
Time Limit: 1 sec
0 <= Data of a node <= 10^5
Sample Input 1:
10 3 20 30 40 2 40 50 0 0 0 0 


Sample Output 1:
10:20,30,40
20:40,50
30:
40:
40:
50:

*/