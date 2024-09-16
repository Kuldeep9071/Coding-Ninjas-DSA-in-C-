#include <bits/stdc++.h>
using namespace std;
#include<unordered_map>

void printIntersection(int arr1[], int arr2[], int n, int m) {
    unordered_map<int,int> M;
    if(m<n){
        for(int i=0;i<n;i++){
            if(M.count(arr1[i])>0) M[arr1[i]]++;
            else M[arr1[i]]=1;
        }

        for(int j=0;j<m;j++){
            if(M[arr2[j]]>0){
                cout<<arr2[j]<<endl;
                M[arr2[j]]--;
                if(M[arr2[j]]==0){
                    M.erase(arr2[j]);
                }
            }
        }
    }
    else{
        for(int i=0;i<m;i++){
            if(M.count(arr2[i])>0) M[arr2[i]]++;
            else M[arr2[i]]=1;
        }
        for(int j=0;j<n;j++){
            if(M[arr1[j]]>0){
                cout<<arr1[j]<<endl;
                M[arr1[j]]--;
                if(M[arr1[j]]==0){
                    M.erase(arr1[j]);
                }
            }
        }
    }
}

/*
Problem statement
You have been given two integer arrays/lists (ARR1 and ARR2) of size N and M, respectively.
 You need to print their intersection; An intersection for this problem can be defined
  when both the arrays/lists contain a particular value or to put it in other words,
   when there is a common value that exists in both the arrays/lists.

Note :
Input arrays/lists can contain duplicate elements.

The intersection elements printed would be in the order they appear in the second array


Detailed explanation ( Input/output format, Notes, Images )
Constraints :
0 <= N <= 10^6
0 <= M <= 10^6

Time Limit: 1 sec 
Sample Input 1 :
6
2 6 8 5 4 3
4
2 3 4 7 
Sample Output 1 :
2
3 
4
Sample Input 2 :
4
2 6 1 2
5
1 2 3 4 2
Sample Output 2 :
1 
2 
2
*/