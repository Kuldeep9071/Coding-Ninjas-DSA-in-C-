/*
Problem statement
Given an array of n integers, find and return the pointer type reference to the highest element of the array. For example if the array is "1 2 3 4 5", you have to return the pointer type variable holding the address of "5".

Detailed explanation ( Input/output format, Notes, Images )
Constraints
 1<= n <=10^6
-10^6 <= ar[i] <= 10^6
Note
You just have to write the definiton of the given function template and return the corresponding pointer type reference. No need of taking any input or printing any output.
Sample Input 1
 2
-56 10
Sample Output
10
Sample Input 2
4
1 2 3 4
Sample Output 2
4
*/
#include<bits/stdc++.h>
using namespace std;
int* findmax(int *ar,int n)
{
    int max=*ar;
    int *p=ar;
    int i=1;
    while(i<n){
        if(*(ar+i)>max){
            p=ar+i;
            max=*(ar+i);
        }
        i++;
    }
    return p;
}