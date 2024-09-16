/*
Problem statement
Given the 'start' and the 'end'' positions of the array 'input'. Your task is to sort the elements between 'start' and 'end' using quick sort.



Note :
Make changes in the input array itself.
Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8
Sample Input 2 :
5
1 2 3 5 7
Sample Output 2 :
1 2 3 5 7 
Constraints :
1 <= N <= 10^3
0 <= input[i] <= 10^9

*/




#include<iostream>
using namespace std;


int partitionArray(int input[], int start, int end) {

	int x=input[start];
	int countSmall=0;
	for(int k=start;k<=end;k++){
		if(input[k]<x){
			countSmall++;
		}
	}
	swap(input[start],input[start+countSmall]);
	int i=start;
	int j=end;
	while(i!=start+countSmall && j!=start+countSmall){
		if(input[i]<x){
			i++;
		}
		else if(input[j]>=x){
			j--;
		}
		else{
			swap(input[i],input[j]);
			i++;
			j--;
		}
	}

	return countSmall;
}

void quickSort(int input[], int start, int end) {
	
	if(start>=end){
		return;
	}

	int smallcount=partitionArray(input,start,end);

	quickSort(input,start,start+ smallcount-1);
	quickSort(input,start+smallcount+1, end);

}