#include<bits/stdc++.h>
using namespace std;
#include<math.h>

int main()
{   unsigned int tc;
    cin>>tc;
    for(unsigned int k=0;k<tc;k++){
        unsigned int n;
        cin>>n;
        vector<unsigned int> data(n+1);
        unsigned int div=pow(10,9)+7;
        data[0]=0;
        data[1]=1;
        data[2]=2;
        data[3]=4;
        for(unsigned int i=4;i<=n;i++){
            data[i]=(data[i-1]+data[i-2]+data[i-3])%div;
        }
        unsigned int ans=data[n];
        cout<<ans%div<<endl;
    }
}

/*
Problem statement
A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 
3 steps at a time. Implement a method to count how many possible ways the child can 
run up to the stairs. You need to return all possible number of ways.

Time complexity of your code should be O(n).

Since the answer can be pretty large soo print the answer with mod(10^9 +7)

Detailed explanation ( Input/output format, Notes, Images )

Constraints :
1 <= T < = 10
1 <= N <= 10^5
Sample input 1
2
2
3
Sample output 1
2
4
Explanation of sample input 1:
Test case 1:
To reach at top of 2nd stair, we have only two options i.e (2), (1,1)

Test case 2:
 To reach at top of 3rd stair, we have four options i.e (1,1,1), (1,2) ,(2,1), (3)
Sample input 2:
2
5
10
Sample output 2:
13
274

*/