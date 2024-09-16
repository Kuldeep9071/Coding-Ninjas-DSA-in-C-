#include <string.h>
#include<map>
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void printAllPossibleCodes(string input,string output="") {
   map<string,char> keyMap;
    char ch='a';
    for(int i=1;i<=26;i++,ch++) keyMap[to_string(i)]=ch;
    if(input==""){
        cout<<output<<endl;
        return;
    }
    printAllPossibleCodes(input.substr(1),output+keyMap[string(1,input[0])]);
    if(input.size()>1 && stoi(input.substr(0,2))<=26)
        printAllPossibleCodes(input.substr(2),output+keyMap[input.substr(0,2)]);
}

/*

Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S.
Write a program to print the list of all possible codes that can be generated from the given string.

Note : The order of codes are not important. Just print them in different lines.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= Length of String S <= 10

Sample Input:
1123
Sample Output:
aabc
kbc
alc
aaw
kw

*/