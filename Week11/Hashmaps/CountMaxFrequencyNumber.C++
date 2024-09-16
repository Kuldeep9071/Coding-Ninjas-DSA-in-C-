#include<bits/stdc++.h>
using namespace std;
#include<unordered_map>

int highestFrequency(int arr[], int n) {
    if(n<1) return INT_MIN;
    unordered_map<int,int> M;
    for(int i=0;i<n;i++){
        if(M.count(arr[i])>0) M[arr[i]]+=1;
        else M[arr[i]]=1;
    }
    int max=M[arr[0]];
    int ans=arr[0];
    for(int i=1;i<n;i++){
        if(M[arr[i]]>max){
            max=M[arr[i]];
            ans=arr[i];
        }
    }
    return ans;
}