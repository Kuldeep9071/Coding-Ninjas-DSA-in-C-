#include <iostream>
using namespace std;

#include<bits/stdc++.h>
#include<unordered_map>

bool Find(vector<vector<char>> &C,int last,int n,int m,int i,int j,vector<vector<bool>> & visited,unordered_map<int,char> &M){
    if(last==0) return true;
    if(i+1>=0 && j>=0 && i+1<n && j<m && C[i+1][j]==M[last] && visited[i+1][j]==0){
        visited[i+1][j]=1;
        if(Find(C, last-1,n, m, i+1,j, visited,M)) return true;
        visited[i+1][j]=0;
    }
    if(i+1>=0 && j+1>=0 && i+1<n && j+1<m && C[i+1][j+1]==M[last] && visited[i+1][j+1]==0){
        visited[i+1][j+1]=1;
        if(Find(C, last-1,n, m,  i+1,j+1, visited,M)) return true;
        visited[i+1][j+1]=0;
    }
    if( i>=0 && j+1>=0 && i<n && j+1<m && C[i][j+1]==M[last] && visited[i][j+1]==0){
        visited[i][j+1]=1;
        if(Find(C, last-1,n, m,  i,j+1, visited,M)) return true;
        visited[i][j+1]=0;
    }
    if(i-1>=0 && j+1>=0 && i-1<n && j+1<m && C[i-1][j+1]==M[last] && visited[i-1][j+1]==0){
        visited[i-1][j+1]=1;
        if(Find(C, last-1,n, m,  i-1,j+1, visited,M)) return true;
        visited[i-1][j+1]=0;
    }
    if(i-1>=0 && j>=0 && i-1<n && j<m && C[i-1][j]==M[last] && visited[i-1][j]==0){
        visited[i-1][j]=1;
        if(Find(C, last-1,n, m,  i-1,j, visited,M)) return true;
        visited[i-1][j]=0;
    }
    if(i-1>=0 && j-1>=0 && i-1<n && j-1<m && C[i-1][j-1]==M[last] && visited[i-1][j-1]==0){
        visited[i-1][j-1]=1;
        if(Find(C, last-1,n, m,  i-1,j-1, visited,M)) return true;
        visited[i-1][j-1]=0;
    }
    if(i>=0 && j-1>=0 && i<n && j-1<m && C[i][j-1]==M[last] && visited[i][j-1]==0){
        visited[i][j-1]=1;
        if(Find(C, last-1,n, m,  i,j-1, visited,M)) return true;
        visited[i][j-1]=0;
    }
    if(i+1>=0 && j-1>=0 && i+1<n && j-1<m && C[i+1][j-1]==M[last] && visited[i+1][j-1]==0){
        visited[i+1][j-1]=1;
        if(Find(C, last-1,n, m,  i+1,j-1, visited,M)) return true;
        visited[i+1][j-1]=0;
    }
    return false;
}

int main(){
    int n,m;
    cin>>n;
    cin>>m;
    vector<pair<int,int>> Start;
    vector<vector<char>> C(n,vector<char> (m));
    for(int i;i<n;i++){
        for(int j=0;j<m;j++){
            char a;
            cin>>a;
            C[i][j]=a;
            if(a=='C') Start.push_back({i,j});
        }
    }
    bool ans=0;
    unordered_map<int,char> M;
    M[10]='O';
    M[9]='D';
    M[8]='I';
    M[7]='N';
    M[6]='G';
    M[5]='N';
    M[4]='I';
    M[3]='N';
    M[2]='J';
    M[1]='A';
    vector<vector<bool>> visited(n,vector<bool>(m,0));
    // cout<<Start.size()<<endl;
    for(int i=0;i<Start.size();i++){
        visited[Start[i].first][Start[i].second]=1;
        // cout<<Start[i].first <<" "<<Start[i].second<<endl;
        if(Find(C,10,n,m,Start[i].first,Start[i].second,visited,M)){
            ans=1;
            break;
        }
        visited[Start[i].first][Start[i].second]=0;
    }
    if(ans) cout<<1;
    else cout<<0;
}

/*
Problem statement
Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there 
is a path in the given matrix which makes the sentence “CODINGNINJA” .

There is a path from any cell to all its neighbouring cells. For a particular cell, neighbouring
 cells are those cells that share an edge or a corner with the cell.

Detailed explanation ( Input/output format, Notes, Images )

Constraints :

1 <= N <= 1000
1 <= M <= 1000

Time Limit: 1 second

Sample Input 1:
2 11
CXDXNXNXNXA
XOXIXGXIXJX
Sample Output 1:
1
*/