/*
Problem statement
Take two numbers as input and swap them and print the swapped values by using the concept of functions and pointers.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= 'T' <= 10^2
-10^5 <= 'a', 'b' <= 10 ^ 5

Time Limit: 1 sec
Note
You don't have to print anything .Just complete the definition of the given function.
Sample Input 1:
2
1 2 
3 4
Sample Output 1:
2 1
4 3
Explanation For Sample Input 1:
The output of the above test case is 2 1 for the first test case.
The output of the 2nd test case is 4 3.
Sample Input 2:
2
5 6
7 8
Sample Output 2:
6 5
8 7
Explanation For Sample Input 2:
The output of the above test case is  6 5 for the first test case.
The output of the 2nd test case is 8 7.
*/

#include<iostream>
using namespace std;

void swap(int *a,int *b){
    int p = *a;
    *a = *b;
    *b = p;
}