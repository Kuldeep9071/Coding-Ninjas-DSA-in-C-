#include <iostream>
using namespace std;

#include<vector>

bool HasPath(vector<vector<int>> &A,int e,int v,vector<int> & visited,int src,int dest){
    if(src==dest) return true;
    visited[src]=true;
    for(int i=0;i<v;i++){
        if(A[src][i]==1 && visited[i]==0) 
        if( HasPath(A,e,v,visited,i,dest)){
            return true;
        }
    }
    return false;
}

int main() {
    int v,e;
    cin>>v;
    cin>>e;
    vector<int> visited(v,0);
    vector<vector<int>> A(v,vector<int>(v));
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a;
        cin>>b;
        A[a][b]=1;
        A[b][a]=1;
    }
    int src,dest;
    cin>>src;
    cin>>dest;
    bool ans= HasPath(A,e,v,visited,src,dest);
    if(ans==true){
        cout<<"true";
    }else{
        cout<<"false";
    }
}

/*
Problem statement
Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), check if there exists any path between them or not. Print true if the path exists and false otherwise.

Note:

1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
0 <= V <= 1000
0 <= E <= 1000
0 <= a <= V - 1
0 <= b <= V - 1
0 <= v1 <= V - 1
0 <= v2 <= V - 1
Time Limit: 1 second
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
true
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
false

*/