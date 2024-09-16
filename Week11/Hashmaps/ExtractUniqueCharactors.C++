#include <bits/stdc++.h>
using namespace std;
#include<unordered_map>

string uniqueChar(string str) {
	string ans;
    unordered_map<string,bool> M;
    for(int i=0;i<str.size();i++){
        if(M.count(str.substr(i,1))==1) continue;
        else M[str.substr(i,1)]=1;
    }
    int i=0;
    while(i<str.size()){
       if(M[str.substr(i,1)]==1){
           ans.append(str.substr(i,1));
           M[str.substr(i,1)]=0;
       }
        i++;
    }
    return ans;
}
/*
Problem statement
Given a string S, you need to remove all the duplicates. That means, 
the output string should contain each character only once. 
The respective order of characters should remain same, as in the input string.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
0 <= Length of S <= 10^8
Time Limit: 1 sec
Sample Input 1 :
ababacd
Sample Output 1 :
abcd
Sample Input 2 :
abcde
Sample Output 2 :
abcde
*/