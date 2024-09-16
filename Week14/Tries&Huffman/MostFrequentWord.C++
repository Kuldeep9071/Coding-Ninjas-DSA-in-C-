#include <bits/stdc++.h> 
using namespace std;
#include<unordered_map>

string mostFrequentWord(string &a, string &b) {
    vector<int> SpaceIdxA;
    SpaceIdxA.push_back(0);
	for(int i=0;i<a.size();i++){
        if(a[i]==' ') SpaceIdxA.push_back(i);
    }
    SpaceIdxA.push_back(a.size());
    vector<int> SpaceIdxB;
    SpaceIdxB.push_back(0);
	for(int i=0;i<b.size();i++){
        if(b[i]==' ') SpaceIdxB.push_back(i);
    }
    SpaceIdxB.push_back(b.size());
    unordered_map<string,int> WordFreqA;
    unordered_map<string,int> WordFreqB;
    for(int i=0;i<SpaceIdxA.size()-1;i++){
        if(i==0) WordFreqA[a.substr(SpaceIdxA[i],SpaceIdxA[i+1]-SpaceIdxA[i])]++;
        else WordFreqA[a.substr(SpaceIdxA[i]+1,SpaceIdxA[i+1]-SpaceIdxA[i]-1)]++;
    }
    for(int i=0;i<SpaceIdxB.size()-1;i++){
        if(i==0) WordFreqB[b.substr(SpaceIdxB[i],SpaceIdxB[i+1]-SpaceIdxB[i])]++;
        else WordFreqB[b.substr(SpaceIdxB[i]+1,SpaceIdxB[i+1]-SpaceIdxB[i]-1)]++;
    }
    string ans="";
    int max=INT_MIN;
    for (auto x:WordFreqA){
        if(!WordFreqB.count(x.first)){
            if(x.second>max){
                max=x.second;
                ans=x.first;
            }
            if(x.second==max){
                ans=min(ans,x.first);
            }
        }
    }
    if(ans=="") return "-1";
    return ans;
}

/*
Problem statement
You are given two strings 'A' and 'B' of words. Your task is to find out the most frequent and
 lexicographically smallest word in string 'A', which is not present in string 'B'. If no such
  word is present in 'A', then return -1.

Note:

1. A word is a sequence of one or more lowercase characters.
2. Words are separated by a single whitespace character.

Example:
For the given string 'A' = “coding ninjas coding ninjas” and 'B' = “data structures and algorithms”,
 so both the word 'coding' and 'ninjas' are not present in string 'B' and occur two times each,
  but the word “coding” is lexicographically smaller than the word “ninjas”. So the answer is 
  “coding”.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= |A|, |B| <= 10^5 

Where |A|, |B| denotes the length of string 'A' and 'B' respectively.   

Time limit: 1 sec
Sample Input 1:
2
yuvraj hit six sixes in six balls
yuvraj is a cricketer
coding ninjas coding ninjas
computer science
Sample Output 1:
six
coding
Explanation for Sample Output 1:
In test case 1, “six” is the only word which occurs the most number of times in string 'A' and
 is not present in string 'B'.

In test case 2, both the word “coding” and “ninjas” occur two times in string 'A' and is not
 present in string 'B'. Since, the word “coding” is lexicographically smaller than “ninjas”,
  hence we return “coding”.


Sample Input 2:
2
a a b b c c d
a b d
this algorithm repeats the same process again and again
this algorithm repeats the same process again and again
Sample Output 2:
c
-1
Explanation for Sample Output 2:
In test case 1, the words “a”, “b” and “c” occur 3 times in string 'A', but “a” and “b” are 
present in 'B'. Hence, we return “c”.

In test case 2, both the strings are equal. Hence we return an -1 as there is no such word which
 is present in 'A', but not present in 'B'.

*/