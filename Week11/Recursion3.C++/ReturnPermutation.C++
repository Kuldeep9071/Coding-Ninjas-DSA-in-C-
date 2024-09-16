#include <string>
using namespace std;

int returnPermutations(string input, string output[]){
   	if(input.empty()){
		output[0]="";
		return 1;
	}
	
	string out[1000];
	int size=returnPermutations(input.substr(1),out);
	for(int i = 0;i<size;i++){
		for(int j = 0;j<out[i].size()+1;j++){
			output[i*output[i].size()+j]= out[i].substr(0,j)+input[0]+out[i].substr(j);
		}
	}
    return size*(out[0].size()+1);
}

/*
Problem statement
Given a string S, find and return all the possible permutations of the input string.

Note 1 : The order of permutations is not important. Note 2 : If original string 
contains duplicate characters, permutations will also be duplicates.


Detailed explanation ( Input/output format, Notes, Images )
Sample Input :
abc
Sample Output :
abc
acb
bac
bca
cab
cba
*/