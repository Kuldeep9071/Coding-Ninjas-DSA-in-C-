// #include<iostream>
// using namespace std;


// #include<bits/stdc++.h>

// class Edge{
//     public:
//     int p,q,w;
// };
// void PrimsMST(vector<vector<int>> &A,vector<bool> &Glanced,vector<bool> &visited,vector<int> &Parent,int v,int e,vector<Edge> &Output,vector<int> &VrtxVal){
//     int minWei=INT_MAX;
//     int minIdx=-1;
//     int Curr=-1;
//     for(int j=0;j<v;j++){
//         if(visited[j]){
//             for(int i=0;i<v;i++){
//                 if(i==j) continue;
//                 if(!Glanced[i] && A[j][i]<minWei && !visited[i]) {
//                     minWei=A[j][i];
//                     minIdx=i;
//                     Curr=j;
//                 }
//             }
//         }
//     }
//     if(minWei==INT_MAX) return;
//     if(minWei<VrtxVal[minIdx]) VrtxVal[minIdx]=minWei;
//     Parent[minIdx]=Curr;
//     Glanced[Curr]=1;
//     visited[minIdx]=1;
//     PrimsMST(A,Glanced,visited,Parent,v,e,Output,VrtxVal);
//     Edge Edge1;
//     Edge1.p=Curr;
//     Edge1.q=minIdx;
//     Edge1.w=VrtxVal[minIdx];
//     Output.push_back(Edge1);
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
//     vector<Edge> Output;
//     vector<int> Parent(v,-1);
//     vector<bool> Glanced(v,0);
//     vector<bool> visited(v,0);
//     visited[0]=1;
//     vector<int> VrtxVal(v,INT_MAX);
//     PrimsMST(A,Glanced,visited,Parent,v,e,Output,VrtxVal);
//     for(int i=0;i<Output.size();i++){
//         if(Output[i].p>Output[i].q) cout<<Output[i].q<<" "<<Output[i].p<<" "<<Output[i].w<<"\n";
//         else cout<<Output[i].p<<" "<<Output[i].q<<" "<<Output[i].w<<"\n";
//     }
// }




// #include <iostream>
// using namespace std;

// int main() {
//     // Write your code here
// }



#include <iostream>
#include <climits>
using namespace std;

int minimum(bool *visited, int *weight, int n){
    int s = INT_MAX;
    int current_index = 0;
    for (int i = 0; i < n; i++){
        if (!visited[i] && s > weight[i]){
            s = weight[i];
            current_index = i;
        }
    }
    return current_index;
}

void prim_algorithm(int **edges, int n){
    bool *visited = new bool[n];
    int *weight = new int[n];
    int *parent = new int[n];

    for (int i = 0; i < n; i++){
        visited[i] = false;
        weight[i] = INT_MAX;
        parent[i] = -1;
    }

    for (int i = 0; i < n - 1; i++){
        int current = minimum(visited, weight, n);
        for (int j = 0; j < n; j++){
            if (edges[current][j] > 0 && (weight[j] > edges[current][j]) && !visited[j]){
                weight[j] = edges[current][j];
                parent[j] = current;
            }
        }
        visited[current] = true;
    }
    
    for (int i = 1; i < n; i++){
        int p = parent[i];
        cout << min(i, p) << " " << max(i, p) << " " << edges[i][p] << endl;
    }
}

int main(){
    int n, e;
    cin >> n >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++){
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }
    for (int i = 0; i < e; i++){
        int s, d, w;
        cin >> s >> d >> w;
        edges[s][d] = w;
        edges[d][s] = w;
    }
    prim_algorithm(edges, n);
}