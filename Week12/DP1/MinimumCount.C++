#include<bits/stdc++.h>
using namespace std;
#include<unordered_map>

int helper(int n,unordered_map<int,int>& M){
	if(M.count(n)) return M[n];
	int i=1;
	int Least=INT_MAX;
	while(n-i*i>=0){
		int a=helper(n-i*i,M);
		if(a<Least) Least=a;
		i++;
	}
	M[n]=1+Least;
	return 1+Least;
}

int minCount(int n){
	unordered_map<int,int> M;
	M[0]=0;
	M[1]=1;
	M[2]=2;
	M[3]=3;
	return helper(n,M);
}

/*
Problem statement
Given an integer N, find and return the count of minimum numbers 
required to represent N as a sum of squares.

That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. The output
 will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares.

Detailed explanation ( Input/output format, Notes, Images )

Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec
Sample Input 1 :
12
Sample Output 1 :
3
Explanation of Sample Output 1 :

12 can be represented as : 

A) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)

B) (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2) + (1^2)  + (2 ^ 2)

C) (1^2) + (1^2) + (1^2) + (1^2) + (2 ^ 2) + (2 ^ 2)

D) (2 ^ 2) + (2 ^ 2) + (2 ^ 2)

As we can see, the output should be 3.
Sample Input 2 :
9
Sample Output 2 :
1
*/