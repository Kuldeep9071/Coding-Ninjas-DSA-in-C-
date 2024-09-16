/*
Problem statement
Given an array ar of n integers, reverse the elements of the array by using the concept of pointers.

Detailed explanation ( Input/output format, Notes, Images )
Constraints
1<= n <=10^6
-10^6<= ar[i] <= 10^6
Note
 You only have to complete the definition of the given function named "reverse". Input has already been taken for you.
Sample Input :
4
1
2
3
4
Sample Output :
4 3 2 1 

*/

void reverse(int *ar,int n){
	int i=0;
	int *p=(ar+n-1);
	int temp;
	while(i<n/2){
		temp=*(ar+i);
		*(ar+i)=*(p-i);
		*(p-i)=temp;
		i++;
	}
}