#include <string>
using namespace std;

#include <bits/stdc++.h>
#include<unordered_map>

int keypad(int num, string output[]){
    if(num==0 || num==1){
        output[0]="";
        return 1;
    }
  

    unordered_map<int,string> keyValue;

    keyValue[2]="abc";
    keyValue[3]="def";
    keyValue[4]="ghi";
    keyValue[5]="jkl";
    keyValue[6]="mno";
    keyValue[7]="pqrs";
    keyValue[8]="tuv";
    keyValue[9]="wxyz";

    int size=keypad(num/10, output);

    int lastdigit=num%10;

    string letters=keyValue[lastdigit];

    int newsize=size*letters.size();
    string temp[newsize];

    int sizefactor=0;
    for(int i=0;i<letters.size();i++){
        for(int j=0;j<size;j++){
            temp[sizefactor]=output[j]+letters[i];
            sizefactor++;
        }
    }

    for(int i=0;i<newsize;i++)
    {
        output[i]=temp[i];
    }
    return newsize;
}




/*
Problem statement
Given an integer n, using phone keypad find out 
all the possible strings that can be made using digits of input n.

Return empty string for numbers 0 and 1.

Note :
1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the
 output array and return the count of elements populated in the output array.


Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= n <= 10^6

Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf

*/