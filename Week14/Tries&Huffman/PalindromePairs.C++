#include <bits/stdc++.h> 
using namespace std;

void reverse(string s){
    for(int i=0;i<s.size()/2;i++){
        swap(s[i],s[s.size()-1-i]);
    }
}
bool isPalindrome(string s){
    if(s.size()<=1) return true;
    int i=0;
    int j=s.size()-1;
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++;
        j--;
    }
    return true;
}
vector<vector<int>> countPalindromicPairs(vector<string> &words){
    vector<vector<int>> ans;
    for(int i=0;i<words.size();i++){
        for(int j=0;j<words.size();j++){
             if(i==j) continue;
            string s=words[i];
            s.append(words[j]);
            if(isPalindrome(s)){
                ans.push_back({i,j});
            }
        }
    }
    return ans;
}

/*
Problem statement
You are given a list of ‘N’ words ‘WORDS’. Your task is to return all pairs of the distinct 
indices (i, j) in ‘WORDS’, such that the concatenation of WORDS[i] and WORDS[j] is a palindrome.

For Example:

You are given ‘WORDS’ = [“cat”, “mat”, “tac”]. Then the answer will be [(0, 2), (2, 0)}, 
because “cat” + “tac” = “cattac” which is a palindrome and “tac” + “cat” = “taccat” which
 is also a palindrome.

Detailed explanation ( Input/output format, Notes, Images )

Constraints:
1 <= T <= 10
2 <= N <= 1000
0 <= WORDS[i].LENGTH <= 100
WORDS[i] consists of lowercase English letters

Time Limit: 1 sec
Sample Input 1:
2
3
cat
mat
tac
3
ab  
ba
bb
Sample Output 1:
0 2 
2 0
0 1
1 0
Explanation of Sample Input 1:
For the first test case, the answer will be [(0, 2), (2, 0)], because “cat” + “tac” = “cattac” 
which is a palindrome, and “tac” + “cat” = “taccat” which is also a palindrome.

For the second test case, the answer will be [(0, 1), (1, 0)], because “ab” + “ba” = “abba”
 which is a palindrome, and “ba” + “ab” = “baab” which is also a palindrome.
 
Sample Input 2:
2
2
abc 
cba
3
wow
bow 
wob 
Sample Output 2:
0 1
1 0
1 2
2 1

*/