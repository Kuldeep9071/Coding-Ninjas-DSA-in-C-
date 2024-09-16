#include<bits/stdc++.h>
using namespace std;
#include<stack>

void reverseStack(stack<int> &input, stack<int> &extra) {
    stack<int> temp;
    while(!input.empty()){
        temp.push(input.top());
        input.pop();
    }
    while(!temp.empty()){
        extra.push(temp.top());
        temp.pop();
    }
    while(!extra.empty()){
        input.push(extra.top());
        extra.pop();
    }
}