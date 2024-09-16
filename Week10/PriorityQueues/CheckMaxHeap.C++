#include<bits/stdc++.h>
using namespace std;

bool helper(int arr[], int n,int i){
    if((2*i+2>n && 2*i+1>n)) return true;
    if(2*i+2<n && arr[2*i+2]>arr[i]) return false;
    if(2*i+1<n && arr[2*i+1]>arr[i]) return false;
    bool b1;
    bool b2;
    bool a1=0;
    bool a2=0;
    if( 2*i+2<n && arr[2*i+2]<arr[i]){
        b1=helper(arr,n,2*i+2);
        a1=1;
    }
    else if(2*i+1<n && arr[2*i+1]<arr[i]){
        b2=helper(arr,n,2*i+1);
        a2=1;
    }
    if(a2 && a1){
        return b1&b2;
    }
    else if(a1 && !a2){
        return b1;
    }
    else if(a2 && !a1){
        return b2;
    }
    else return true;
}

bool isMaxHeap(int arr[], int n) {
    if(n==0 || n==1) return true;
    int i=0;
    while(i<n){
        if( 2*i+2<n){
            if(arr[2*i+2]>arr[i]) return false;
            else return isMaxHeap(arr+2*i+2, n-2-2*i);
        }
        else if(2*i+1<n){
            if(arr[2*i+1]>arr[i]) return false;
            else return isMaxHeap(arr+2*i+1, n-1-2*i);
        }
        else return true;
    }

}