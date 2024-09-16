/*Problem statement
You are given an integer array/list(ARR) of size N. It contains only 0s, 1s and 2s.
 Write a solution to sort this array/list in a 'single scan'.

'Single Scan' refers to iterating over the array/list just once or to put it in other words,
 you will be visiting each element in the array/list just once.

Note:
1. You need to change in the given array/list itself. Hence, no need to return or print anything. 
2. You are not allowed to sort the list/array directly.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= t <= 10^2
0 <= N <= 10^5
Time Limit: 1 sec
Sample Input 1:
1
7
0 1 2 0 2 0 1
Sample Output 1:
0 0 0 1 1 2 2 
Explanation:  The array contains three 0s, two 1s, and two 2s. After sorting the array 
in a single scan, the 0s should come first, then the 1s, and finally the 2s. 
So the output is 0 0 0 1 1 2 2.
Sample Input 2:
2
5
2 2 0 1 1
7
0 1 2 0 1 2 0
Sample Output 2:
0 1 1 2 2 
Explanation: The array contains one 0, two 1s, and two 2s. After sorting,
 the 0 comes first, then the 1s, and finally the 2s. So the output is 0 1 1 2 2.
0 0 0 1 1 2 2
Explanation: The array contains three 0s, two 1s, and two 2s. After sorting,
the 0s come first, then the 1s, and finally the 2s. So the output is 0 0 0 1 1 2 2.*/


#include<iostream>
using namespace std;
#include<bits/stdc++.h>

void sort012(int *arr, int n)
{
    int i=0;
    int j=0;
    for(int x=0;x<n;x++){
        if(arr[x]==0){
            i++;
        }
        else if(arr[x]==1){
            j++;
        }
    }
    int k=n-i-j;
    int p=0;
    int q=0;
    for(;p<i;p++){
        arr[q++]=0;
    }
    p=0;
    for(;p<j;p++){
        arr[q++]=1;
    }
    p=0;
    for(;p<k;p++){
        arr[q++]=2;
    }
}