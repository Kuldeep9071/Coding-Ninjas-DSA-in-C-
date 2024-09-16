#include<bits/stdc++.h>
using namespace std;

vector<int> kSmallest(int arr[], int n, int k) {
    priority_queue<int> ans;
    int i=0;
    while(i<k){
        ans.push(arr[i]);
        i++;
    }
    while(i<n){
        if(arr[i]<ans.top()){
            ans.pop();
            ans.push(arr[i]);
        }
        i++;
    }
    vector<int> data;
    while(!ans.empty()){
        data.push_back(ans.top());
        ans.pop();
    }
    return data;
}