#include <iostream>
#include<queue>

using namespace std;

void printBFS(int **edge,int n,int sv,bool *visited){
    queue<int>q;
    q.push(sv);
     visited[sv]=true;
    while(!q.empty()){
        int ci=q.front();
        cout<<ci<<" "; 
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
        if(!visited[i])
        printBFS(edge,n,i,visited);
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
