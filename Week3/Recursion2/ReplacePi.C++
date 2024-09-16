/*
Problem statement
Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".

Constraints :
1 <= |S| <= 50
where |S| represents the length of string S. 
Constraints :
1 <= |S| <= 50
where |S| represents the length of string S. 
Sample Input 1 :
xpix
Sample Output :
x3.14x
Sample Input 2 :
pipi
Sample Output :
3.143.14
Sample Input 3 :
pip
Sample Output :
3.14p
Constraints:-
1<= |S|<=50

*/
void replacePi(char input[]) {

	int n=0;
	while(input[n]!='\0'){
		n++;
	}

	if(input[0]=='\0'){
		return;
	}
	
	if( input[0]=='p' && input[1]=='i'){
		int j=n+2;
		input[j]='\0';
		for(;j>0;j--){
			input[j]=input[j-1];
		}
		int k=n+1;
		for(;k>0;k--){
			input[k]=input[k-1];
		}

		input[0]='3';
		input[1]='.';
		input[2]='1';
		input[3]='4';
		replacePi(input+4);
	}
	else{
		replacePi(input+1);
	}

}


