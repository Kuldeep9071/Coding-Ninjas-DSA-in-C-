#include <bits/stdc++.h> 
using namespace std;

bool isValid(int i, int j, vector<vector<int>> &maze, int n) {
    return (i >= 0 && i < n && j >= 0 && j < n && maze[i][j] == 1);
}

void RateMaze(vector<vector<int>> &maze, vector<vector<int>> &ans, vector<vector<int>> &Board, int n, int i, int j) {
    if (i == n - 1 && j == n - 1) {
        vector<int> path;
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                path.push_back(Board[x][y]);
            }
        }
        ans.push_back(path);
        return;
    }
    //down
    if (isValid(i + 1, j, maze, n) && Board[i + 1][j] != 1) {
        Board[i + 1][j] = 1;
        RateMaze(maze, ans, Board, n, i + 1, j);
        Board[i + 1][j] = 0;
    }
    //right
    if (isValid(i, j + 1, maze, n) && Board[i][j + 1] != 1) {
        Board[i][j + 1] = 1;
        RateMaze(maze, ans, Board, n, i, j + 1);
        Board[i][j + 1] = 0;
    }
    //up
    if (isValid(i - 1, j, maze, n) && Board[i - 1][j] != 1) {
        Board[i - 1][j] = 1;
        RateMaze(maze, ans, Board, n, i - 1, j);
        Board[i - 1][j] = 0;
    }
    //left
    if (isValid(i, j - 1, maze, n) && Board[i][j - 1] != 1) {
        Board[i][j - 1] = 1;
        RateMaze(maze, ans, Board, n, i, j - 1);
        Board[i][j - 1] = 0;
    }
}

vector<vector<int>> ratInAMaze(vector<vector<int>> &maze, int n) {
    vector<vector<int>> ans;
    vector<vector<int>> Board(n, vector<int>(n, 0));
    if (maze[0][0] == 1) {
        Board[0][0] = 1;
        RateMaze(maze, ans, Board, n, 0, 0);
    }
    return ans;
}

/*
Problem statement
You are given a 'N' * 'N' maze with a rat placed at 'MAZE[0][0]'. Find and print all paths
 that rat can follow to reach its destination i.e. 'MAZE['N' - 1]['N' - 1]'. Rat can move
  in any direc­tion ( left, right, up and down).

Value of every cell in the 'MAZE' can either be 0 or 1. Cells with value 0 are blocked means
 the rat can­not enter into those cells and those with value 1 are open.

Detailed explanation ( Input/output format, Notes, Images )

Constraints:
1 <= N <= 10
0 <= MAZE[i][j] <=1

Where 'MAZE[i][j]' denotes the value in the cell of 'MAZE'.

Time Limit: 1 sec
Sample Input 1 :
3
1 0 1
1 0 1
1 1 1
Sample Output 1 :
1 0 0 1 0 0 1 1 1 
Explanation for Sample Output 1:
Only 1 path is possible which contains coordinate < (1,1), (2,1), (3,1), (3,2) and (3,3)

So our path matrix will look like this:

1 0 0
1 0 0
1 1 1

Which is returned from left to right and then top to bottom in one line.
Sample Input 2 :
2
1 0
0 1
Sample Output 2 :
 [Blank]
Explanation for Sample Output 2:
As no path is possible to the last cell, a blank vector will be returned and nothing is printed.

*/