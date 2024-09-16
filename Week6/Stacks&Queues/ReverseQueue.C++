#include<bits/stdc++.h>
using namespace std;
#include<stack>
#include<queue>

void reverseQueue(queue<int> &input) {
	stack <int> temp;
    while(!input.empty()){
        temp.push(input.front());
        input.pop();
    }
    while(!temp.empty()){
        input.push(temp.top());
        temp.pop();
    }
}