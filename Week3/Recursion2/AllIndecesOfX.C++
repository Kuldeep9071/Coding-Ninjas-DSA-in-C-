/*
Problem statement
Given an array of length N and an integer x, you need to find all the indexes where x is present in the input array. Save all the indexes in the output array (in increasing order).

Do this recursively. Indexing in the array starts from 0.

Hint:
Try making a helper function with the required arguments and call the helper function from the allIndexes function.
Detailed explanation ( Input/output format, Notes, Images )

Constraints :
1 <= N <= 10^3
Sample Input :
5
9 8 10 8 8
8
Sample Output :
1 3 4

*/


int allIndexes(int input[], int size, int x, int output[]) {
  int count=0;
  int k=0;
  for(int i=0;i<size;i++){
    if(input[i]==x){
      output[k]=i;;count++;
      k++;
    }
  }
  return  count;
}
