#include <bits/stdc++.h> 
using namespace std;
#include <iostream>
#include <cstring>
#include<unordered_map>

using namespace std;

bool isPermutation(char input1[], char input2[]) {

    unordered_map<char,int> M1;
    unordered_map<char,int> M2;
    int i=0;
    while(input1[i]!='\0' && input2[i]!='\0'){
        if(M1.count(input1[i])==1) M1[input1[i]]++;
        else M1[input1[i]]=1;
        if(M2.count(input2[i])==1) M2[input2[i]]++;
        else M2[input2[i]]=1;
        i++;
    }
    if(input1[i]!=input2[i]) return false;
    else{
        int it=0;
        while(input1[it]!='\0'){
            if(M2[input1[it]]!=M1[input1[it]]) return false;
            it++;
        }
        it=0;
        while(input2[it]!='\0'){
            if(M2[input2[it]]!=M1[input2[it]]) return false;
            it++;
        }
        return true;
    }
}

/*
Problem statement
For a given two strings, 'str1' and 'str2', check whether they are a permutation 
of each other or not.

Permutations of each other
Two strings are said to be a permutation of each other when either of the string's
 characters can be rearranged so that it becomes identical to the other one.

Example: 
str1= "sinrtg" 
str2 = "string"

The character of the first string(str1) can be rearranged to form str2 and hence
 we can say that the given strings are a permutation of each other.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
0 <= N <= 10^6
Where N is the length of the input string.

Time Limit: 1 second
Sample Input 1:
abcde
baedc
Sample Output 1:
true
Sample Input 2:
abc
cbd
Sample Output 2:
false
*/
