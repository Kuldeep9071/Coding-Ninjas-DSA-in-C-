#include<bits/stdc++.h>
using namespace std;

void heapsort(vector<int>&arr,int n){
    if(n==0 || n==1) return;
    int i=0;
    while(i<n){
        int max=i;
        if(2*i+2<n && arr[2*i+2]>arr[max]) max=2*i+2;
        if(2*i+1<n && arr[2*i+1]>arr[max]) max=2*i+1;
        if(i==max) break;
        else{
            swap(arr[i],arr[max]);
            i=max;
        }
    }
    swap(arr[0],arr[n-1]);
    heapsort(arr,n-1);
}
vector<int> mergeKSortedArrays(vector<vector<int>*> input) {
    vector<int> ans;
    for(int i=input.size()-1;i>=0;i--){
        for(int j=input[i]->size()-1;j>=0;j--){
            ans.push_back((*input[i])[j]);
        }
        delete input[i];
    }
    int n=ans.size();
    int k=0;
    while(k<n){
        int i=k;
        while(i>0){
            int j=(i-1)/2;
            if(ans[i]>ans[j]){
                swap(ans[i],ans[j]);
                i=j;
            }
            else break;
        }
        k++;
    }
    heapsort(ans,ans.size());
    return ans;
}