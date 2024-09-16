#include<bits/stdc++.h>
using namespace std;
#include<unordered_map>
#include<unordered_map>

int getPairsWithDifferenceK(int *arr, int n, int k) {
	int ans=0;
	unordered_map<int,int> M;
	for(int i=0;i<n;i++){
		M[arr[i]]++;
	}
	for(int i=0;i<n;i++){
		if(M.count(arr[i])==1){
			if(k==0){
				ans+=(M[arr[i]]*(M[arr[i]]-1))/2;
			}
			if(M.count(arr[i]+k)!=1 && M.count(arr[i]-k)!=1 && k!=0){
			}
			else if(M.count(arr[i]+k)==1 && M.count(arr[i]-k)!=1&& k!=0 ){
				ans+=M[arr[i]]*M[arr[i]+k];
			}
			else if(M.count(arr[i]+k)!=1 && M.count(arr[i]-k)==1&& k!=0){
				ans+=M[arr[i]]*M[arr[i]-k];
			}
			else if(M.count(arr[i]+k)==1 && M.count(arr[i]-k)==1&& k!=0){
				ans+=M[arr[i]]*M[arr[i]+k]+M[arr[i]]*M[arr[i]-k];
			}
			M.erase(arr[i]);
		}
	}
	return ans;
}
/*
Problem statement
You are given with an array of integers and an integer K. You have to find and 
print the count of all such pairs which have difference K.

Note: Take absolute difference between the elements of the array.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
0 <= n <= 10^4
Time Limit: 1 sec
Sample Input 1 :
4 
5 1 2 4
3
Sample Output 1 :
2
Explanation
(5,2) and (1,4) are the possible combinations as their absolute difference is 3.
Sample Input 2 :
4
4 4 4 4 
0
Sample Output 2 :
6
*/