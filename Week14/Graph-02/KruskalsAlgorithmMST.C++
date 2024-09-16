#include<bits/stdc++.h>
using namespace std;

class Edge{
    public:
    int p,q,w;
};

 bool compareInput(const Edge& x, const Edge& y){
    return x.w < y.w;
 }
  bool compareOutput(const Edge& x, const Edge& y){
    if(x.p < y.p) return true;
    else{
        return  x.q < y.q;
    }
}

int main() {
    int v,e;
    cin>>v>>e;
    vector<Edge> Input(e);
    for(int k=0;k<e;k++){
        int a,b,c;
        cin>>a>>b>>c;
        Input[k].p=a;
        Input[k].q=b;
        Input[k].w=c;
    }
    sort(Input.begin(),Input.end(),compareInput);
    vector<Edge> Output;
    vector<int> Parent;
    for(int i=0;i<v;i++) Parent.push_back(i);
    for(int i=0;i<e;i++){
        int a=Input[i].p;
        int b=Input[i].q;
        if(Parent[a]==Parent[b]){
            continue;
        }
        else{
            Output.push_back(Input[i]);
            for(int j=0;j<=v;j++){
                if(j!= b && Parent[j]==Parent[b]) Parent[j]=Parent[a];
            }
            Parent[b]=Parent[a];
        }
    }
    for(int i=0;i<Output.size();i++){
        if(Output[i].p>Output[i].q) cout<<Output[i].q<<" "<<Output[i].p<<" "<<Output[i].w<<"\n";
        else cout<<Output[i].p<<" "<<Output[i].q<<" "<<Output[i].w<<"\n";
    }
}



/*
Problem statement
Given an undirected, connected and weighted graph G(V, E) with V number of vertices 
(which are numbered from 0 to V-1) and E number of edges.

Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.

For printing MST follow the steps -

1. In one line, print an edge which is part of MST in the format - 
v1 v2 w
where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w.
 And v1  <= v2 i.e. print the smaller vertex first while printing an edge.

2. Print V-1 edges in above format in different lines.

Note : Order of different edges doesn't matter.

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
1 2 1
0 1 3
0 3 5
Input Graph
*/