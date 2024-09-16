#include<bits/stdc++.h>
using namespace std;
#include<limits>

int helper(int n,unordered_map<int,int> &M){
	if(M.count(n)==1) return M[n];
	int a=INT_MAX;
	int b=INT_MAX;
	int c=INT_MAX;
	if(n%3==0){
		if(M.count(n/3)) c=M[n/3];
		else{
			c=helper(n/3,M);
			M[n/3]=c;
		}
	}
	if(n%2==0 ){
		if(M.count(n/2)) b=M[n/2];
		else{
			b=helper(n/2,M);
			M[n/2]=b;
		}
	}
	
	if(M.count(n-1)){
		a=M[n-1];
	}
	else{
		a=helper(n-1,M);
		M[n-1]=a;
	}
	M[n]=1+min(a,min(b,c));
	return M[n];
}
int countStepsToOne(int n){
	unordered_map<int,int> M;
	M[0]=0;
	M[1]=0;
	M[2]=1;
	M[3]=1;
	return helper(n,M);
}