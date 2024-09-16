/*Problem statement

Given a string S, compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*".

Detailed explanation ( Input/output format, Notes, Images )

Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.

Sample Input 1 :
hello
Sample Output 1:
hel*lo
Sample Input 2 :
aaaa
Sample Output 2 :
a*a*a*a

*/

// Change in the given string itself. So no need to return or print the changed string.

void pairStar(char input[]) {
    int n=0;
    while(input[n]!='\0'){
        n++;
    }
    if(input[0]=='\0'){
        return;
    }
    if(input[0]==input[1]){
        int i=n;
        for(;i>0;i--){
            input[i]=input[i-1];
        }
        input[1]='*';
        pairStar(input+2);
    }
    pairStar(input+1);
}
