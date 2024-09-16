#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int>&arr, int k,int n){
    if(k==0) return;
    int i=0;
    while(i<n){
        int min=i;
        if(2*i+2<n && arr[2*i+2]>arr[min]) min=2*i+2;
        if(2*i+1<n && arr[2*i+1]>arr[min]) min=2*i+1;
        if(i==min) break;
        else{
            swap(arr[i],arr[min]);
            i=min;
        }
    }
    swap(arr[0],arr[n-1]);
    heapify(arr,k-1,n-1);
}

int kthLargest(vector<int>&arr, int k) {
    int n=arr.size();
    int p=0;
    while(p<n){
        int i=p;
        while(i>0){
            int j=(i-1)/2;
            if(arr[j]<arr[i]){
                swap(arr[i],arr[j]);
                i=j;
            }
            else break;
        }
        p++;
    }
    heapify(arr,k,n);
    return arr[n-k];
}