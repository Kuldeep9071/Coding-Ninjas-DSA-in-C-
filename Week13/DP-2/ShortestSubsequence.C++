#include<bits/stdc++.h>
using namespace std;

int solve(string s,string v){
    int MAX=1001;
    int m = s.size(), n =v.size();
    int dp[m+1][n+1];
    for (int i = 0; i <= m; i++) dp[i][0] = 1;
    for (int i = 0; i <= n; i++) dp[0][i] = MAX;
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            char ch = s[i-1];
            int k;
            for (k = j-1; k >= 0; k--)
            if (v[k] == ch) break;
            if (k == -1) dp[i][j] = 1;
            else dp[i][j] = min(dp[i-1][j], dp[i-1][k] + 1);
        }
    }
    int ans = dp[m][n];
    if (ans >= MAX) ans = -1;
    return ans;
}

/*
Problem statement
Gary has two string S and V. Now, Gary wants to know the length shortest subsequence in S, which is not a subsequence in V.

Note: The input data will be such that there will always be a solution.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= |S| <= 1000 (|x| implies the length of the string x)
1 <= |V| <= 1000 
Time Limit: 1 second
Sample Input 1:
babab
babba
Sample Output 1:
3
Explanation:
"aab" is the shortest subsequence which is present in S and absent in V.
*/