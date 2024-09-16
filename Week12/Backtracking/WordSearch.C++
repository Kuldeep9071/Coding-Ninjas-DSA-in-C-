#include<bits/stdc++.h>
#include <unordered_map> 
using namespace std;

bool isValid(vector < vector < char >> & arr,vector<vector<bool>> & visited,int n,int m,int x,int y,string &word){
    if(x<0 || x>=n || y<0 || y>=m || visited[x][y]==1 || arr[x][y]!=word[0]) return false;
    return true;
}

bool searchWord(vector<vector<char>> &board,vector<vector<bool>> &visited,string word,int n, int m,int x,int y){
    if(word.size()==0) return true;
    if(isValid(board,visited,n,m,x,y,word)){
        visited[x][y]=0;
        return (searchWord(board,visited,word.substr(1),n,m,x+1,y) ||
                searchWord(board,visited,word.substr(1),n,m,x,y+1) || 
                searchWord(board,visited,word.substr(1),n,m,x-1,y) || 
                searchWord(board,visited,word.substr(1),n,m,x,y-1));       
    }
    else return false;
}

bool present(vector<vector<char>> &board, string &word, int n, int m) {
    if(word=="") return false;
    vector<vector<bool>> visited(n,vector<bool> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            visited[i][j]=0;
        }
    }
    vector<pair<int,int>> PossibleStart;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==word[0]){
                PossibleStart.push_back({i,j});
            }
        }
    }
    if(PossibleStart.size()==0) return false;
    for(auto it:PossibleStart){
        if(searchWord(board,visited,word,n,m,it.first,it.second)) return true;
    }
    return false;
}

/*
Problem statement

You are given a 2D board('N' rows and 'M' columns) of characters and a string 'word'.

Your task is to return true if the given word exists in the grid, else return false. 
The word can be constructed from letters of sequentially adjacent cells, where adjacent
 cells are horizontally or vertically neighboring.



Note:
The same letter cell should not be used more than once.
For Example:
For a given word “design” and the given 2D board 

[[q’, ‘v’, ‘m’, ‘h’],
 [‘d’, ‘e’, ‘s’, ‘i’],
 [‘d’, ‘g’, ‘f’, ‘g’],
 [‘e’, ‘c’, ‘p’, ‘n’]]

The word design can be formed by sequentially adjacent cells as shown by the
 highlighted color in the 2nd row and last column.
board

Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
coding
4 4
c z k l
o d i a
r g n m
m r s d
Sample Output 1:
true
Explanation For Sample Input 1:
For the given word, and grid we can construct from letters of sequentially adjacent 
cells as shown below:
board

Sample Input 2:
ninjas
4 4
c d k s
o d s i
d g n j
e r i n
Sample Output 2:
false
Constraints:
1 <= N <= 6
1 <= M <= 6
1 <= |word| <=20

Time Limit: 1 sec

*/