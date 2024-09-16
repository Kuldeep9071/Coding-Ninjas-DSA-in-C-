#include<bits/stdc++.h>
using namespace std;

int knapsack(int *weights, int *values, int n, int maxWeight){
	if(maxWeight<=0) return 0;
	if(n==0) return 0;
	if(weights[0]<=maxWeight){
		return max(knapsack(weights+1,values+1,n-1,maxWeight),values[0]+knapsack(weights+1,values+1,n-1,maxWeight-weights[0]));
	}
	else{
		return knapsack(weights+1,values+1,n-1,maxWeight);
	}
}
/*
Problem statement
A thief robbing a store can carry a maximal weight of W into his knapsack. There are N items,
 and i-th item weigh 'Wi' and the value being 'Vi.' What would be the maximum value V,
  that the thief can steal?

Detailed explanation ( Input/output format, Notes, Images )

Constraints :
1 <= N <= 20
1<= Wi <= 100
1 <= Vi <= 100

Time Limit: 1 sec
Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output 1 :
13
Sample Input 2 :
5
12 7 11 8 9
24 13 23 15 16
26
Sample Output 2 :
51
*/
