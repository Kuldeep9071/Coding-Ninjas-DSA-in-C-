/*
Problem statement
You have been given an integer array/list(ARR) and a number 'num'. Find and return the total number of pairs in the array/list which sum to 'num'.

Note:
Given array/list can contain duplicate elements. 
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= t <= 10^2
0 <= N <= 10^4
0 <= num <= 10^9

Time Limit: 1 sec
Sample Input 1:
1
9
1 3 6 2 5 4 3 2 4
7
Sample Output 1:
7
Sample Input 2:
2
9
1 3 6 2 5 4 3 2 4
12
6
2 8 10 5 -2 5
10
Sample Output 2:
0
2


 Explanation for Input 2:
Since there doesn't exist any pair with sum equal to 12 for the first query, we print 0.

For the second query, we have 2 pairs in total that sum up to 10. They are, (2, 8) and (5, 5).
*/
#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int pairSum(int *arr, int n, int num)
{
    sort(arr,arr+n);

    int i=0;
    int ans=0;
    int j=n-1;

    while(i<j){

        if((arr[i]+arr[j])>num){
            j--;
        }
        else if((arr[i]+arr[j])<num){
            i++;
        }
        else{

            if(arr[i]==arr[j]){
                int n=j-i+1;
                if(n%2==0){
                    ans+=(n/2)*(n-1);
                }
                else{
                    ans+=n*(n-1)/2;
                }
                return ans;
            }
            else{
                int count1=0;
                int count2=0;
                int temp1=arr[i];
                int temp2=arr[j];
                while(arr[i]==temp1){
                    count1++;
                    i++;
                }
                while(arr[j]==temp2){
                    count2++;
                    j--;
                }
                ans+=count1*count2;
            }
        }
    }
    return ans;
}