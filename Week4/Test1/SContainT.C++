/*Problem statement
Given two string s and t, write a function to check if s contains all characters of t
 (in the same order as they are in string t).

Return true or false.

Do it recursively.

E.g. : s = “abchjsgsuohhdhyrikkknddg” contains all characters of t=”coding” 
in the same order. So function will return true.

Detailed explanation ( Input/output format, Notes, Images )

Sample Input 1 :
abchjsgsuohhdhyrikkknddg
coding
Sample Output 1 :
true

Sample Input 2 :
abcde
aeb
Sample Output 2 :
false

*/

#include<iostream>
using namespace std;
#include<bits/stdc++.h>

pair<int,bool> isPresent(char *large,char *small){
    int m=0;
    while(large[m]!='\0'){
        m++;
    }
    for(int i=0;i<m;i++){
        if(large[i]==small[0]){
            return {i,true};
        }
    }
    return {0,false};
}

bool checksequenece(char large[] , char*small) {
    
    if(small[0]=='\0'){
        return true;
    }
    else{
        if((isPresent(large, small)).second==1){
            checksequenece(large+1+(isPresent(large, small)).first, small+1);
        }
        else{
            return false;
        }
    }
}
