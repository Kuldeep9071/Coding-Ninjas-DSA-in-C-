// #include <iostream>
// using namespace std;

// #include<bits/stdc++.h>

// int ClosestVertex(vector<vector<int>> &A,vector<int> &ans,vector<bool> &visited,int v,int src){
//     int EdgeLen=INT_MAX;
//     int idx=-1;
//     for(int i=0;i<v;i++){
//         if(i==src) continue;
//         if(A[src][i]<ans[i]) ans[i]=A[src][i]+ans[src];
//         if(!visited[i] && A[src][i]<EdgeLen){
//             EdgeLen=A[src][i];
//             idx=i;
//         }
//     }
//     return idx;
// }

// void Dijkstra(vector<vector<int>> &A,vector<int> &ans,vector<bool> &visited,int v,int e,int src){
//     int idx=ClosestVertex(A,ans,visited, v, src);
//     if(idx==-1) return;
//     visited[src]=1;
//     Dijkstra(A,ans,visited,v,e,idx);
// }

// int main() {
//     int v,e;
//     cin>>v>>e;
//     vector<vector<int>> A(v,vector<int>(v,INT_MAX));
//     for(int k=0;k<e;k++){
//         int a,b,c;
//         cin>>a>>b>>c;
//         A[a][b]=c;
//         A[b][a]=c;
//     }
//     // cout<<"Kuldeep\n";
//     vector<int> ans(v,INT_MAX);
//     ans[0]=0;
//     vector<bool> visited(v,0);
//     Dijkstra(A,ans,visited,v,e,0);
//     for(int i=0;i<ans.size();i++){
//         cout<<i<<" "<<ans[i]<<"\n";
//     }
//     return 0;
// }








#include <iostream>
#include <climits>
using namespace std;

int findMinVertex(bool *visited, int *distance, int n){
    int min = INT_MAX;
    int min_index = 0;
    for (int i = 0; i < n; i++){
        if (min > distance[i] && !visited[i]){
            min = distance[i];
            min_index = i;
        }
    }
    return min_index;
}

void dijkstra_algorithm(int **edges, int n){
    bool *visited = new bool[n];
    int *distance = new int[n];

    for (int i = 0; i < n; i++){
        visited[i] = false;
        distance[i] = INT_MAX;
    }
    distance[0] = 0;

    for (int i = 0; i < n - 1; i++){
        int current = findMinVertex(visited, distance, n);
        visited[current] = true;
        for (int j = 0; j < n; j++){
            if (edges[current][j] > 0 && !visited[j]){
                int distance_to_reach = distance[current] + edges[current][j];
                int distance_earlier = distance[j];
                if (distance_to_reach < distance_earlier)
                {
                    distance[j] = distance_to_reach;
                }
            }
        }
    }

    for (int i = 0; i < n; i++){
        cout << i << " " << distance[i] << endl;
    }

    delete[] visited;
    delete[] distance;
}

int main(){
    int n, e;
    cin >> n >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++){
        edges[i] = new int[n];
        for (int j = 0; j < n; j++){
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++){
        int s, d, w;
        cin >> s >> d >> w;
        edges[s][d] = w;
        edges[d][s] = w;
    }

    dijkstra_algorithm(edges, n);

    for (int i = 0; i < n; i++){
        delete[] edges[i];
    }
    delete[] edges;

    return 0;
}

/*
Problem statement
Given an undirected, connected and weighted graph G(V, E) with V number of vertices
 (which are numbered from 0 to V-1) and E number of edges.

Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all
 other vertices (including source vertex also) using Dijkstra's Algorithm.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
2 <= V, E <= 10^5
Time Limit: 1 sec
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Input Graph

Sample Output 1 :
0 0
1 3
2 4
3 5


Input Graph
*/