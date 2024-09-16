#include<bits/stdc++.h>
using namespace std;

bool helper(int n,int x,int y,vector<int> &M){
	if(n<=0) return 0;
	if(M[n]!=-1){
		if(M[n]==1) return 1;
		return 0;
	}
	bool p=helper(n-1,x,y,M);
	bool q=helper(n-x,x,y,M);
	bool r=helper(n-y,x,y,M);
	M[n]=(p^1 || q^1 || r^1);
	return M[n];
}

string findWinner(int n, int x, int y){
	vector<int> M(n+1,-1);
	M[1]=1;
	M[x]=1;
	M[y]=1;
	if(helper(n,x,y,M)) return "Beerus";
	return "Whis";
}


/*
Problem statement
Whis and Beerus are playing a new game today. They form a tower of N coins and make a move in 
alternate turns. Beerus plays first. In one step, the player can remove either 1, X, or Y coins
 from the tower. The person to make the last move wins the game. Can you find out who wins the game?

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= N <= 10 ^ 6
2 <= X <= Y<= 50

Time Limit: 1 sec
Sample Input 1 :
4 2 3
Sample Output 1 :
Whis
Sample Input 2 :
10 2 4
Sample Output 2 :
Beerus
Explanation to Sample Input 1:

Initially, there are 4 coins,  In the first move, Beerus can remove either 1, 2, or 3 coins
 in all three cases, Whis can win by removing all the remaining coins. 

*/