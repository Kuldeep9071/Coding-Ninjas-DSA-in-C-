/*
Write a recursive function to convert a given string into the number it represents. That is input will be a numeric string that contains only numbers, you need to convert the string into corresponding integer and return the answer.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
0 < |S| <= 9
where |S| represents length of string S.
Sample Input 1 :
00001231
Sample Output 1 :
1231
Sample Input 2 :
12567
Sample Output 2 :
12567

*/

#include<math.h>
int stringToNumber(char input[]) {
    int n=0;
    while(input[n]!='\0'){
        n++;
    }
    if(input[0]=='\0'){
        return 0;
    }
    int ans=input[0]-48;
    return (ans)*(pow(10,n-1))+stringToNumber(input+1);
}


