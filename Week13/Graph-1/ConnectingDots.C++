#include <iostream>
using namespace std;

const int MAX_N = 1000;
const int MAX_M = 1000;

int n, m;

char board[MAX_N][MAX_M];
bool visited[MAX_N][MAX_M];

bool isValid(int x, int y, char color) {
    return (x >= 0 && x < n && y >= 0 && y < m && board[x][y] == color);
}

bool isCycle(int x, int y, int startX, int startY, char color, int length) {
    if (visited[x][y]) {
        if (x == startX && y == startY && length >= 4)
            return true;
        else
            return false;
    }
    visited[x][y] = true;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isValid(nx, ny, color) && isCycle(nx, ny, startX, startY, color, length + 1))
            return true;
    }
    visited[x][y] = false;
    return false;
}

bool hasCycle() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && isCycle(i, j, i, j, board[i][j], 1))
                return true;
        }
    }
    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            visited[i][j] = false;
        }
    }
    bool result = hasCycle();
    if (result)
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}

/*
Problem statement
Gary has a board of size NxM. Each cell in the board is a coloured dot. There exist only 26 colours
 denoted by uppercase Latin characters (i.e. A,B,...,Z). Now Gary is getting bored and wants 
 to play a game. The key of this game is to find a cycle that contain dots of same colour.
  Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the
   following condition:

1. These k dots are different: if i ≠ j then di is different from dj.
2. k is at least 4.
3. All dots belong to the same colour.
4. For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should also be adjacent.
    Cells x and y are called adjacent if they share an edge.
    Since Gary is colour blind, he wants your help. Your task is to determine if there exists
    a cycle on the board.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :

2 <= N <= 1000
2 <= M <= 1000
Time Limit: 1 second

Sample Input 1:
3 4
AAAA
ABCA
AAAA

Sample Output 1:
true
*/