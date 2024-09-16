#include <iostream>
using namespace std;

#include<vector>
#include<queue>
#include<unordered_map>

void GetPath(vector<vector<bool>> & A, vector<bool> & visited,int v,int e,int src,int dest,vector<int> &Path,unordered_map<int,int> ptr){
    queue<int> Q;
    Q.push(src);
    visited[src]=1;
    while(!Q.empty()){
        int a=Q.front();
        Q.pop();
        if(a==dest){
            while(ptr.count(a)){
               cout<<a<<" ";
                a=ptr[a];
            }
            cout<<src;
            return;
        }
        for(int i=0;i<v;i++){
            if(i==a) continue;
            if(A[a][i] && !visited[i]){
                Q.push(i);
                visited[i]=1;
                ptr[i]=a;
            }
        }
    }
}

int main() {
    int v,e;
    cin>>v;
    cin>>e;
    vector<bool> visited(v,0);
    vector<int> Path;
    vector<vector<bool>> A(v,vector<bool> (v,0));
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a;
        cin >> b;
        A[a][b] = 1;
        A[b][a] = 1;
    }
    int src, dest;
    cin >> src;
    cin >> dest;
    unordered_map<int,int> ptr;
    GetPath(A,visited,v,e,src,dest,Path,ptr);
    for(int i=0;i<Path.size();i++){
        cout<<Path[i]<<" ";
    }
}

/*
Problem statement
Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), find and print the path 
from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.

Find the path using BFS and print the shortest path available.

Note:

1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
4. Save the input graph in Adjacency Matrix.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
2 <= V <= 1000
1 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
0 <= v1 <= 2^31 - 1
0 <= v2 <= 2^31 - 1
Time Limit: 1 second
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
3 0 1
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :*/