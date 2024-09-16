/*Problem statement
Given a string, compute recursively a new string where all 'x' chars have been removed.

Detailed explanation ( Input/output format, Notes, Images )

Constraints :
1 <= |S| <= 10^3
where |S| represents the length of string S. 

Sample Input 1 :
xaxb
Sample Output 1:
ab
Sample Input 2 :
abc
Sample Output 2:
abc
Sample Input 3 :
xx
Sample Output 3:

*/

void removeX(char input[]) {

    int n=0;
    while(input[n]!='\0'){
        n++;
    }
  
  if(input[0]=='\0'){
      return;
  }

    if(input[0]=='x'){
        for(int i=0;i<n;i++){
            input[i]=input[i+1];
        }
        if(input[0]=='x'){
            return removeX(input);
        }
    }
    return removeX(input+1);
}
