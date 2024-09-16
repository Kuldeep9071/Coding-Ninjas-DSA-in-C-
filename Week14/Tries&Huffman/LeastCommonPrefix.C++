#include <bits/stdc++.h> 
using namespace std;
#include<unordered_map>

string com_prefix(string out1, string out2){
	string out;
	int n1 = out1.length(), n2 = out2.length();
	for (int i = 0, j = 0; i < n1 && j < n2; i++, j++){
		if (out1[i] != out2[j])
		{
			break;
		}
		out.push_back(out1[i]);
	}
	return out;
}

string commonPrefix(vector<string> &arr, int n){
	string prefix = arr[0];

	// Iterating over all the strings and finding the common prefix.
	for (int i = 1; i < n; i++){
		prefix = com_prefix(prefix, arr[i]);
	}

	// Base case of no common prefix.
	if (prefix == ""){
		return "-1";
	}

	return prefix;
}





/*
Problem statement
You are given an array ‘arr’ of ‘n’ strings.



Find the longest common prefix in all these strings.



If there is no common prefix in all the strings return "-1".


Example:
Input: 'arr' = [“abcd”, “abc”, “abref”, “abcde”]

Output: ab

Explanation:
Answer is “ab”, as it is the longest prefix present in all the given strings.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
4
Codingninjas
Coding
Coders
Codezen


Sample Output 1:
Cod   


Explanation of sample output 1:
In the given testcase, the longest prefix that is present in all the strings is “Cod”.
 Hence the answer is “Cod”. 

Sample Input 2:
3
abcd
Abcd
abc
Sample Output 2:
-1


Explanation of sample output 2:
In the given testcase, there is no prefix that is present in all the strings.
 Hence the answer is “-1”


Constraints:
1 <= ‘n’ <= 10^3
1 <= ‘arr[i].length’ <= 10^3

Time Limit: 1 sec


Expected Time Complexity:
Try solving this in O(n).

*/