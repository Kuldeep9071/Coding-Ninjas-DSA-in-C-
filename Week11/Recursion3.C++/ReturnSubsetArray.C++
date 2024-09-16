int subset(int input[], int n, int output[][20]) {
	if(n==0){
		output[0][0]=0;
		return 1;
	}
	else{
		int smallOutput=subset(input+1,n-1,output);
		int i,j;
		for(i=0;i<smallOutput;i++){
			output[smallOutput+i][0]=output[i][0]+1;
			output[smallOutput+i][1]=input[0];
			for(j=2;j<=output[i][0]+1;j++) output[smallOutput+i][j]=output[i][j-1];
		}
		return 2*smallOutput;
	}
}

/*
Problem statement
Given an integer array (of length n), find and return all the subsets of input array.

NOTE- Subsets are of length varying from 0 to n, that contain elements of the array. 
But the order of elements should remain same as in the input array.

Note :
The order of subsets are not important.


Detailed explanation ( Input/output format, Notes, Images )
Sample Input:
3
15 20 12
Sample Output:
[] (this just represents an empty array, don't worry about the square brackets)
12 
20 
20 12 
15 
15 12 
15 20 
15 20 12 

*/
