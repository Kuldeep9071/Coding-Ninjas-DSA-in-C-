#include<bits/stdc++.h>
using namespace std;

bool isValid(int row, int col, vector<vector<int>> &Board, int n) {
    for (int i = 0; i < row; i++)  if (Board[i][col] == 1) return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) if (Board[i][j] == 1) return false;
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) if (Board[i][j] == 1) return false;
    return true;
}

void NQueen(vector<vector<int>> &ans, int n, vector<vector<int>> &Board, int row) {
    if (row == n) {
        vector<int> PossibleConfig;
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) PossibleConfig.push_back(Board[i][j]);
        ans.push_back(PossibleConfig);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (isValid(row, i, Board, n)) {
            Board[row][i] = 1;
            NQueen(ans, n, Board, row + 1); 
            Board[row][i] = 0;
        }
    }
}

vector<vector<int>> solveNQueens(int n) {
    vector<vector<int>> ans;
    if (n < 4 && n > 1) return ans;
    vector<vector<int>> Board(n, vector<int>(n, 0));
    NQueen(ans, n, Board, 0);
    return ans;
}

/*
Problem statement
You are given an integer 'N'. For a given 'N' x 'N' chessboard, find a way to place 'N' 
queens such that no queen can attack any other queen on the chessboard.

A queen can be killed when it lies in the same row, or same column, or the same diagonal
 of any of the other queens. You have to print all such configurations.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= 'N' <= 10

Time Limit: 1sec


For Example:
For a chessboard of size 4*4
The configurations are 
alt text

Sample Input 1:
4
Sample Output 1:

0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0
0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 

Explanation For Sample Input 1:
Output depicts two possible configurations of the chessboard for 4 queens.

The Chessboard matrix for the first configuration looks as follows:-

0 0 1 0
1 0 0 0
0 0 0 1
0 1 0 0

Queen contained cell is depicted by 1. As seen, No queen is in the same row, column, 
or diagonal as the other queens. Hence this is a valid configuration.

Sample Input 2:
3
Sample Output2:

      (Blank)
Explanation For Sample Input 2:
Since no possible configuration exists for 3 Queen's.The output remains Empty.

*/