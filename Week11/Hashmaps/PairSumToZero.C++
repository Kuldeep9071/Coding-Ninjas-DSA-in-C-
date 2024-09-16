#include <bits/stdc++.h> 
#include <iostream>
#include <cstring>
#include<unordered_map>

using namespace std;

int pairSum(int *arr, int n) {
	unordered_map<int,int> M;
	int ans=0;
	for(int i=0;i<n;i++){
		if(M.count(arr[i])==1) M[arr[i]]++;
		else M[arr[i]]=1;
	}
	if(M.count(0)==1){
		if(M[0]%2==0){
			ans+=(M[0]/2)*(M[0]-1);
		}
		else{
			ans+=(M[0])*(M[0]-1)/2;
		}
	}
	for(int i=0;i<n;i++){
		if(arr[i]>0){
			if(M.count(-arr[i])==1){
			ans+=(M[arr[i]]*M[-arr[i]]);
			M.erase(arr[i]);
			M.erase(-arr[i]);
			}
			else M.erase(arr[i]);
		}
	}
	return ans;
}
/*Problem statement
Given a random integer array A of size N. Find and print the count of pair
 of elements in the array which sum up to 0.

Note:
Array A can contain duplicate elements as well.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
0 <= N <= 10^4
Time Limit: 1 sec
Sample Input 1:
5
2 1 -2 2 3
Sample Output 1:
2
Explanation
(2,-2) , (-2,2) will result in 0 , so the answer for the above problem is 2.

*/