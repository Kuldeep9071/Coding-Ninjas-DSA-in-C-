#include<bits/stdc++.h>
using namespace std;

#include<vector>

int helper(int *arr, int n,vector<int>&M){
	if(n<=0) return 0;
	if(M[n]!=-1) return M[n];
	int a=helper(arr+1,n-1,M);
	int b=arr[0]+helper(arr+2,n-2,M);
	M[n]=max(a,b);
	return M[n];
}

int maxMoneyLooted(int *arr, int n){
	vector<int> M(n+1,-1);
	return helper(arr,n,M);
}

/*
Problem statement
A thief wants to loot houses. He knows the amount of money in each house. 
He cannot loot two consecutive houses. Find the maximum amount of money he can loot.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec
Sample Input 1 :
6
5 5 10 100 10 5
Sample Output 1 :
110
Sample Input 2 :
6
10 2 30 20 3 50
Sample Output 2 :
90
Explanation of Sample Output 2 :
Looting first, third, and the last houses([10 + 30 + 50]) will result in the maximum loot, 
and all the other possible combinations would result in less than 90.
*/