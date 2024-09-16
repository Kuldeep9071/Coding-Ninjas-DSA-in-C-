/*
Problem statement
Given an integer sorted array (sorted in increasing order) and an element x, find the x in given array using binary search. Return the index of x.

Return -1 if x is not present in the given array. Note : If given array size is even, take first mid.
Input format :

Line 1 : Array size

Line 2 : Array elements (separated by space)

Line 3 : x (element to be searched)

Sample Input :
6
2 3 4 5 6 8 
5 
Sample Output:
3 
Hint : Use helper function to solve this question.

*/


int BS(int input[],int i,int j,int element){

    if(i<=j){
        int m=i+(j-i)/2;
        
        if(input[m]==element){
            return m;
        }
        else if(input[m]>element){
            return BS(input,i,m-1,element);
        } else {
            return BS(input, m + 1, j, element);
        }
    }
    else{
        return -1;
    }
}
int binarySearch(int input[], int size, int element) {
    int i=0;
    int j=size-1;
    BS(input,i,j,element);
}