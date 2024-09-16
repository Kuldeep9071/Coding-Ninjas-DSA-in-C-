#include<bits/stdc++.h>
using namespace std;

int balancedBTsDP(int n) {
    if(n==1) return 1;
    if(n==2) return 3;
    long long int  a=1;
    long long int  b=3;
    long long int  i=3;
    long long int   d=1000000007;
    while(i<=n){
        long long int  ans=((b*(b%d+2*a)%d)%d)%d;
        a=b;
        b=ans;
        i++;
    }
    return b;
}