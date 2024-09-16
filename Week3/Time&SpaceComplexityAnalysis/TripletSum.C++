/*Problem statement
You have been given a random integer array/list(ARR) and a number X. Find and return 
the triplet(s) in the array/list which sum to X.

Note :
Given array/list can contain duplicate elements.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= t <= 10^2
0 <= N <= 10^3
0 <= X <= 10^9

Time Limit: 1 sec
Sample Input 1:
1
7
1 2 3 4 5 6 7 
12
Sample Output 1:
5
Sample Input 2:
2
7
1 2 3 4 5 6 7 
19
9
2 -5 8 -6 0 5 10 11 -3
10
Sample Output 2:
0
5


 Explanation for Input 2:
Since there doesn't exist any triplet with sum equal to 19 for the first query, we print 0.

For the second query, we have 5 triplets in total that sum up to 10. They are,
 (2, 8, 0), (2, 11, -3), (-5, 5, 10), (8, 5, -3) and (-6, 5, 11)*/

#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int twoSum(int *arr,int i,int n,int num){
  int l=i+1;
  int r=n-1;
  int ans=0;
    while(l<r){
      if(arr[l]+arr[r]==num-arr[i]){
          if(arr[l]==arr[r]){
              int m=(r-l+1);
              if(m%2==0){
                  ans+=(m/2)*(m-1);
              }
              else{
                  ans+=(m)*((m-1)/2);
              }
              return ans;
          }
          else{
              int temp1=arr[l];
              int temp2=arr[r];
              int x=0;
              int y=0;
              while(arr[l]==temp1){
                  l++;
                  x++;
              }
              while(arr[r]==temp2){
                  r--;
                  y++;
              }
              ans+=x*y;
          }
      }
      else if(arr[l]+arr[r]>num-arr[i]){
          r--;
      }
      else{
          l++;
      }
    }
  return ans;
}
int tripletSum(int *arr, int n, int num){

    int ans=0;
    sort(arr,arr+n);
    int i=0;
    while(i<n-2){
      ans+=twoSum(arr,i,n,num);
      i++;
    }
    return  ans;
}