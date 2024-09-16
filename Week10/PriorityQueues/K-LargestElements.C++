#include<bits/stdc++.h>
using namespace std;

vector<int> kLargest(int input[], int n, int k){
    priority_queue<int,vector<int>,greater<int>> ans;
    int i=0;
    while(i<k){
        ans.push(input[i]);
        i++;
    }
    while(i<n){
        if(input[i]>ans.top()){
            ans.pop();
            ans.push(input[i]);
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