#include<bits/stdc++.h>
using namespace std;
#include<stack>

bool isBalanced(string expression) {
    stack<char> s;
    int i=0;
    while(expression[i]!='\0'){
        if(expression.at(i)=='('){
                s.push('(');
                i++;
        }
        else{
            if(s.empty()){
                return false;
            }
            s.pop();
            i++;
        }
    }
    if(!s.empty()){
        return false;
    }
    return true;
}

/*
Problem statement
For a given a string expression containing only round brackets or parentheses,
 check if they are balanced or not. Brackets are said to be balanced 
 if the bracket which opens last, closes first.



Example:
Expression: (()())
Since all the opening brackets have their corresponding closing brackets, 
we say it is balanced and hence the output will be, 'true'.

You need to return a boolean value indicating whether the expression is balanced or not.

Note:
The input expression will not contain spaces in between.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= N <= 10^7
 Where N is the length of the expression.

Time Limit: 1sec
Sample Input 1 :
(()()())
Sample Output 1 :
true
Sample Input 2 :
()()(()
Sample Output 2 :
false
Explanation to Sample Input 2:
The initial two pairs of brackets are balanced. But when you see, the opening bracket
 at the fourth index doesn't have its corresponding closing bracket which makes it imbalanced
  and in turn, making the whole expression imbalanced. Hence the output prints 'false'.
*/