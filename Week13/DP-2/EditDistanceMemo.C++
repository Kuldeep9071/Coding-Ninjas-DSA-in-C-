#include<bits/stdc++.h>
using namespace std;

int helper(string s1, string s2,vector<vector<int>> &V){
	if(s1.size()==0 || s2.size()==0) return max(s1.size(),s2.size());
	if(s1[0]==s2[0]) return helper(s1.substr(1),s2.substr(1),V);
	else{
		int a=helper(s1,s2.substr(1),V);
		int b=helper(s1.substr(1),s2.substr(1),V);
		int c=helper(s1.substr(1),s2,V);
		return 1+min(a,min(b,c));
	}
}

int editDistance(string s1, string s2) {
	int m=s1.size();
	int n=s2.size();
	vector<vector<int>> V (m+1,vector<int>(n+1));
	return helper(s1,s2,V);
	for(int i=0;i<=m;i++){
		V[i][0]=i;
	}
	for(int i=0;i<=n;i++){
		V[0][i]=i;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(s1[m-i]==s2[n-j]){
				V[i][j]=V[i-1][j-1];
			}
			else{
				int a=V[i][j-1];
				int b=V[i-1][j-1];
				int c=V[i-1][j];
				V[i][j]= 1+min(a,min(b,c));
			}
		}
	}
	return V[m][n];
}