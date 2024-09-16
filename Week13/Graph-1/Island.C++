#include <iostream>
#include<queue>

using namespace std;

void printBFS(int **edge,int n,int sv,bool *visited){
    queue<int>q;
    q.push(sv);
     visited[sv]=true;
    while(!q.empty()){
        int ci=q.front();
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
    int ans=0;
    for(int i=0;i<n;i++){
        if(!visited[i]) {
            printBFS(edge,n,i,visited);
            ans++;
        }
    }
    cout<<ans;
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
An island is a small piece of land surrounded by water . A group of islands is said to be 
connected if we can reach from any given island to any other island in the same group .

 Given V islands (numbered from 0 to V-1) and E connections or edges between islands.
  Can you count the number of connected groups of islands.

Detailed explanation ( Input/output format, Notes, Images )

Constraints :
0 <= V <= 1000
0 <= E <= (V * (V-1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Time Limit: 1 second
Sample Input 1:
5 8
0 1
0 4
1 2
2 0
2 4
3 0
3 2
4 3
Sample Output 1:
1 
*/