#include <iostream>
#include<queue>
#include<bits/stdc++.h>>

using namespace std;

void printBFS(int **edge,int n,int sv,bool *visited,vector<int> &Path){
    queue<int>q;
    q.push(sv);
     visited[sv]=true;
    while(!q.empty()){
        int ci=q.front();
        Path.push_back(ci);
        q.pop();
        
        for(int i=0;i<n;i++){
            if(i==ci){
                continue;
            }
            if(edge[ci][i]==1 and !visited[i]){
                q.push(i);
                visited[i]=true;
            }
        }
    }
}


void BFS(int **edge,int n){
    bool *visited=new bool[n];
    for(int i=0;i<n;i++){
         visited[i]=false;
    }
    for(int i=0;i<n;i++){
        vector<int> Path;
        if(!visited[i])
        printBFS(edge,n,i,visited,Path);
        sort(Path.begin(),Path.end());
        for(int i=0;i<Path.size();i++){
            cout<<Path[i]<<" ";
        }
        cout<<endl;
    }
   delete [] visited;
}


int main() {

    int n, e;
    cin>>n>>e;
    int **edge=new int*[n];
    for(int i=0;i<n;i++){
        edge[i]=new int[n];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            edge[i][j]=0;
        }
    }
     
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edge[f][s]=1;
        edge[s][f]=1;
    }
    BFS(edge,n);
}

/*
Problem statement
Given an undirected graph G(V,E), find and print all the connected components of the given graph G.

Note:

1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3.  You need to take input in main and create a function which should return all the 
    connected components.And then print them in the main, not inside function.
    Print different components in new line. And each component should be printed in
    increasing order (separated by space). Order of different components doesn't matter.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
0 <= V <= 1000
0 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Sample Input 1:
4 2
0 1
2 3
Sample Output 1:
0 1 
2 3 
Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
0 1 3 
2
*/