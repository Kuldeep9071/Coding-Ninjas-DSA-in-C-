#include <bits/stdc++.h> 
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
#include<map>
using namespace std;
#include <queue>
/*--------------------------HeapNode Class------------------*/
template <typename T>
class HeapNode{
public:
    
    T frequency;
    int index;
    HeapNode<T> *left;
    HeapNode<T> *right;

    HeapNode(T frequency, int idx){
        this->frequency = frequency;
        this->index = idx;
        left = NULL;
        right = NULL;
    }

    ~HeapNode(){
        if (left != NULL){
            delete left;
        }
        if (right != NULL){
            delete right;
        }
    }
};
class cmp
{
public:
    bool operator()(HeapNode<int> *a, HeapNode<int> *b){
        return a->frequency > b->frequency;
    }
};
/*---------------------------------------------------------------*/


void Helper(HeapNode<int> *root, string str, vector<string> &ans){
    if (root->left == NULL && root->right == NULL){
        ans[root->index] = str;
        return;
    }

    if (root->left){
        Helper(root->left, str + "0", ans);
    }

    if (root->right){
        Helper(root->right, str + "1", ans);
    }
}

vector<string> MessageEncode(vector<int> &arr){
    int n = arr.size(); 
    
    if (n==1){
        vector<string> ans(1);
        ans[0] = "1";
        return ans;
    }
    priority_queue<HeapNode<int> *, vector< HeapNode<int> *>, cmp> heap;
    for (int i = 0; i < n; i++){
        HeapNode<int> *newNode = new HeapNode<int> (arr[i], i);
        heap.push(newNode);
    }

    while (heap.size() > 1){
        HeapNode<int> *node1 = heap.top();
        heap.pop();

        HeapNode<int> *node2 = heap.top();
        heap.pop();
        HeapNode<int> *newNode = new HeapNode<int> (node1->frequency + node2->frequency, -1);
        newNode->left = node1;
        newNode->right = node2;
        heap.push(newNode);
    }
    HeapNode<int> *root = heap.top();
    vector<string> ans(n);
    Helper(root, "", ans);
    delete root;
    return ans;
}
vector<string> huffmanCode(vector<int> &arr){
    return MessageEncode(arr) ;
}

/*
Problem statement
You are given an array 'ARR' of Integers having 'N' elements. The array contains an encoded
 message. For each index 'i', 'ARR[i]' denotes the frequency of the 'i'th' character in the
  message. The characters are of an alien language having 'N' alphabets. Given the frequency
   of each of the 'N' alphabets in the message, your task is to find out the Huffman codes 
   for each of the 'N' alphabets in the message.

The Huffman Code for a message is the set of codes such that :

1) All codes are binary strings.
2) Each code should be able to determine its corresponding character uniquely.
3) The total numbers of bits used to represent the message are minimized.
Note:

If there are multiple sets of valid Huffman codes for a message. You can print any of them.
For example:

Consider the array ARR = [ 1, 4, 2 ] having 3 elements. 
The array containing Huffman Codes for the above array will be [ '10', '0', '11' ].
 Other Valid Huffman Codes are [ '01', '1', '00' ], [ '00', '1', '01' ] etc. Codes like 
 [ '1', '0', '01' ], [ '1', '10' , '0' ] are some of the invalid Huffman Codes.


Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= N <= 10^4
1 <= ARR[i]  <= 10^4

Where 'T' denotes the number of test cases, 'N' denotes the elements in the array 'ARR', and
 'ARR[i]' denotes the 'i'th' element of the array 'ARR'.

Time Limit: 1 sec
Sample Input 1:
2
3
5 7 6
2
4 3
Sample Output 1:
1
1
Explanation for Sample Input 1:
For the first test case : 
The array representing the Huffman codes will be [ '11', '0', '10' ] . Note that there are 
multiple other possible answers like [ '00', '1' ,'01' ], [ '01', '1', '00' ] etc. All of 
them are valid, so we can return any of them.

For the second test case : 
The array representing the Huffman codes will be [ '0', '1' ]. The array [ '1', '0' ] also 
represents a valid set of Huffman Code.
Sample Input 2:
2
3
1 2 5
4
5 6 3 1
Sample Output 2:
1
1
Explanation for Sample Input 2:
For the first test case : 
The array representing the Huffman codes will be [ '11', '10', '0' ] . 

For the second test case : 
The array representing the Huffman codes will be [ '10', '0', '110', '111' ]. 

*/