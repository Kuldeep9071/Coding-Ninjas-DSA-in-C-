#include<bits/stdc++.h>
using namespace std;

int balancedBTs(int n) {
    if(n==1) return 1;
    if(n==2) return 3;
    if(n==3) return 15;
    long long  int mod=1000000007;
    int a=balancedBTs(n - 1);
    int b=balancedBTs (n - 2);
    return  ((a) * ((2 *b )%mod + a)%mod) % mod;
}

/*
Problem statement

Given an integer h, find the possible number of balanced binary trees of height h.
 You just need to return the count of possible binary trees which are balanced.

This number can be huge, so, return output modulus 10^9 + 7.

Write a simple recursive solution.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= h <= 24
Time Limit: 1 sec
Sample Input 1:
3
Sample Output 1:
15
Sample Input 2:
4
Sample Output 2:
315

*/