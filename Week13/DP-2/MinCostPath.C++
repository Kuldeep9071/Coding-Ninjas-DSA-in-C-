#include<bits/stdc++.h>
using namespace std;

int Helper(int **input,int m,int n,int i,int j){
	if(i>=m||j >=n)return INT_MAX;
	if(i==m-1 && j==n-1) return input[i][j];
	int a,b,c=INT_MAX;
		a=Helper(input,m,n,i,j+1);
		b=Helper(input,m,n,i+1,j+1);
		c=Helper(input,m,n,i+1,j);
	return input[i][j]+min(a,min(b,c));
}

int minCostPath(int **input, int m, int n){
	return Helper(input,m,n,0,0);
}