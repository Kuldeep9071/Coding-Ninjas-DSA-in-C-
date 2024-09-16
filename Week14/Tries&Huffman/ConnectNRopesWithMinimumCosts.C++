#include<bits/stdc++.h>
using namespace std;

int minCost(int arr[], int n){
	if(n==1) return arr[0];
	priority_queue<int,vector<int>,greater<int>> PQ;
	for(int i=0;i<n;i++){
		PQ.push(arr[i]);
	}
	int ans=0;
	while(PQ.size()>1){
		int a=PQ.top();
		PQ.pop();
		int b=PQ.top();
		PQ.pop();
		int x=a+b;
		ans+=x;
		PQ.push(x);
	}
	return ans;
}


/*
Problem statement
There are given n ropes of different lengths, we need to connect these ropes into one rope.
The cost to connect two ropes is equal to sum of their lengths. We need to connect the 
ropes with minimum cost.

Sample Input 1:
    4 4 3 2 6        
Sample Output 1:
   29
*/