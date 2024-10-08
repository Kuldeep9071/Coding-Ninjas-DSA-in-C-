#include<bits/stdc++.h>
using namespace std;
#include<stack>

int countBracketReversals(string input) {
	int ans=0;
	int i=0;
	stack<int> s;
	int n=input.size();
	if(n%2==1){
		return -1;
	}
	while(input[i]!='\0'){
		if(input[i]=='{'){
			s.push(input[i]);
			i++;
		}
		else{
			if(s.empty()){
				s.push(input[i]);
				i++;
			}
			else if(s.top()=='{'){
				s.pop();
				i++;
			}
			else{
				s.push(input[i]);
				i++;
			}
		}
	}
	while(!s.empty()){
		char a=s.top();
		s.pop();
		char b=s.top();
		s.pop();
		if(a==b){
			ans++;
		}
		else{
			ans+=2;
		}
	}
	return ans;
}

/*
Problem statement
For a given expression in the form of a string, find the minimum number of
 brackets that can be reversed in order to make the expression balanced.
  The expression will only contain curly brackets.

If the expression can't be balanced, return -1.

Example:
Expression: {{{{
If we reverse the second and the fourth opening brackets, the whole expression
 will get balanced. Since we have to reverse two brackets to make the
  expression balanced, the expected output will be 2.

Expression: {{{
In this example, even if we reverse the last opening bracket, we would be 
left with the first opening bracket and hence will not be able to make the 
expression balanced and the output will be -1.

Detailed explanation ( Input/output format, Notes)

Constraints:
0 <= N <= 10^6
Where N is the length of the expression.

Time Limit: 1sec
Sample Input 1:
{{{
Sample Output 1:
-1
Sample Input 2:
{{{{}}
Sample Output 2:
1

*/