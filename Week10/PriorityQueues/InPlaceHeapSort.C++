#include<bits/stdc++.h>
using namespace std;
/*----------------Inplace Means Without Using Extra Space--------------------*/
void heapify(int arr[], int n){
    if(n==0 || n==1) return;
    int i=0;
        while(i<n){
            int min=i;
            if(2*i+2<n && arr[2*i+2]<arr[min]) min=2*i+2;
            if(2*i+1<n && arr[2*i+1]<arr[min]) min=2*i+1;
            if(i==min) break;
            else{
                int temp=arr[i];
                arr[i]=arr[min];
                arr[min]=temp;
                i=min;
            }
    }
    int temp=arr[0];
    arr[0]=arr[n-1];
    arr[n-1]=temp;
    heapify(arr,n-1);
}

void heapSort(int arr[], int n){
    if(n==0 || n==1) return;
    int k=0;
    while(k<n){
            int i=k;
            while(i>0){
                int j=(i-1)/2;
                if(arr[j]>arr[i]){
                    int temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
                    i=j;
                }
            else break;
        }
        k++;
    }
    heapify(arr,n);
}