/*
Problem statement
Given two integers M & N, calculate and return their multiplication using recursion. You can only use subtraction and addition for your calculation. No other operators are allowed.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
0 <= M <= 1000
0 <= N <= 1000
Sample Input 1 :
3 
5
Sample Output 1 :
15
Sample Input 2 :
4 
0
Sample Output 2 :
0
*/

int multiplyNumbers(int m, int n) {
    if(m==0 || n==0) return 0;
    return m+multiplyNumbers(m,n-1);

}