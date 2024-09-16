#include<iostream>
using namespace std;

void printSubsetSumToK(int input[], int size, int k,string output="") {
    if(size==0){
        if(k==0){
            cout<<output<<endl;
            return;
        }
        return;
    }
    printSubsetSumToK(input+1,size-1,k,output);
    printSubsetSumToK(input+1,size-1,k-input[0],output+to_string(input[0])+" ");
}

/*
Problem statement
Given an array A and an integer K, print all subsets of A which sum to K.

Subsets are of length varying from 0 to n, that contain elements of the array.
 But the order of elements should remain same as in the input array.


Note :
The order of subsets are not important. Just print them in different lines.


Detailed explanation ( Input/output format, Notes, Images )
Sample Input:
9 
5 12 3 17 1 18 15 3 17 
6
Sample Output:
3 3
5 1
void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here
}


*/