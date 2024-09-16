#include <iostream>
#include <string>
#include<unordered_map>
using namespace std;

void helper(int num,string output){
    if(num==0){
        cout<<output<<endl;
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
    int lastdigit=num%10;
    string letters=keyValue[lastdigit];
    for(int i=0;i<letters.size();i++){
        helper(num/10,letters[i]+output);
    }
}

void printKeypad(int num){
    string output;
    helper(num,output);
}


/*Problem statement
Given an integer n, using phone keypad find out and print all the possible strings that 
can be made using digits of input n. where keypad digits contains following data

    keyValue[2]="abc"
    keyValue[3]="def"
    keyValue[4]="ghi"
    keyValue[5]="jkl"
    keyValue[6]="mno"
    keyValue[7]="pqrs"
    keyValue[8]="tuv"
    keyValue[9]="wxyz"


Note :
The order of strings are not important. Just print different strings in new lines.
Detailed explanation ( Input/output format, Notes)

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