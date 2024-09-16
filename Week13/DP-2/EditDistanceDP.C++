#include<bits/stdc++.h>
using namespace std;

int editDistance(string s1, string s2) {
    int m=s1.size();
	int n=s2.size();
	vector<vector<int>> V (m+1,vector<int>(n+1));
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
