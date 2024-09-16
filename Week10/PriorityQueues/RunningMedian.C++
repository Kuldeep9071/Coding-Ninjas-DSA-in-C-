#include<bits/stdc++.h>
using namespace std;

void findMedian(int *arr, int n){
    if(n<1) return;
    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int>> right;
    left.push(arr[0]);
    cout<<arr[0]<<" ";
    for(int i=1;i<n;i++){
        if(left.top()<arr[i]) right.push(arr[i]);
        else left.push(arr[i]);
        if(left.size()>right.size()+1) {
            right.push(left.top());
            left.pop();
        }
        else if(left.size()<right.size()){
            left.push(right.top());
            right.pop();
        }
        if(i%2==0) cout<<left.top()<<" ";
        else cout<<(left.top()+right.top())/2<<" ";
    }
}