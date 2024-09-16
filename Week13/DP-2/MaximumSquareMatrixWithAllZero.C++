#include<bits/stdc++.h>
using namespace std;

int findMaxSquareWithAllZeros(int **arr, int n, int m){
	vector<vector<int>> V(n,vector<int>(m));
	int max=0;
	for(int j=0;j<n;j++){
		if(arr[j][0]==0) V[j][0]=1;
		else V[j][0]=0;
		if(V[j][0]>max) max=V[j][0];
	}
	for(int j=0;j<m;j++){
		if(arr[0][j]==0) V[0][j]=1;
		else V[0][j]=0;
		if(V[0][j]>max) max=V[0][j];
	}
	for(int k=1;k<n;k++){
		for(int j=1;j<m;j++){
			if(arr[k][j]==0) V[k][j]=1+min(V[k-1][j-1],min(V[k][j-1],V[k-1][j]));
			else V[k][j]=0;
			if(V[k][j]>max) max=V[k][j];
		}
	}

	return max;
}