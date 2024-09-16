#include <bits/stdc++.h> 
#include <iostream>
#include <cstring>
#include<unordered_map>

using namespace std;

int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    unordered_map<int,int> M;
    int ans=INT_MIN;
    int sum=0;
    for(int i=0;i<n;i++){
        if(sum+arr[i]==0 &&  i+1>ans) ans=i+1;
        if(M.count(sum+arr[i])==1){
            if(i-M[sum+arr[i]]>ans)  ans=(i-M[sum+arr[i]]);          
        }
        else M[sum+arr[i]]=i;
        sum+=arr[i];
    }    
    return ans;
}

/*
Problem statement
Given an array consisting of positive and negative integers, find the length of the
 longest subarray whose sum is zero.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
0 <= N <= 10^8
Time Limit: 1 sec
Sample Input 1:
10 
 95 -97 -387 -435 -5 -70 897 127 23 284
Sample Output 1:
5
Explanation:
The five elements that form longest subarray that sum up to zero are:-387,-435,-5,-70,897 

Note: You don't have to print anything. Just complete the definition of the
 function given and return the value accordingly.
*/