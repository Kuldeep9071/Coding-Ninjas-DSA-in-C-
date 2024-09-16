/*Problem statement
You are given the starting 'l' and the ending 'r' positions of the array 'ARR'.


You must sort the elements between 'l' and 'r'.

Note:
Change in the input array itself. So no need to return or print anything.
Example:
Input: ‘N’ = 7,
'ARR' = [2, 13, 4, 1, 3, 6, 28]

Output: [1 2 3 4 6 13 28]

Explanation: After applying 'merge sort' on the input array, the output is [1 2 3 4 6 13 28].
Detailed explanation ( Input/output format, Notes, Images )
Input format :
The first line contains an integer <em>**'N'**</em> representing the size of the array/list.

The second line contains 'N' single space-separated integers representing the elements in the array/list.
Output format :
You don't need to return anything. In the output, you will see the array after you do the modification.


Sample Input 1:
7
2 13 4 1 3 6 28
Sample Output 1:
1 2 3 4 6 13 28
Explanation of Sample Output 1:
After applying 'merge sort' on the input array, the output is [1 2 3 4 6 13 28].


Sample Input 2:
5
9 3 6 2 0
Sample Output 2:
0 2 3 6 9
Explanation of Sample Output 2:
After applying 'merge sort' on the input array, the output is [0 2 3 6 9].


Constraints :
1 <= N <= 10^3
0 <= ARR[i] <= 10^9*/

void mergeSort(int arr[], int l, int r) {
   if(l>=r){
       return;
   }

   int m=l+(r-l)/2;
   mergeSort(arr, l, m);
   mergeSort(arr,m+1,r);

   int *ans = new int[r-l+1];
   
   int x=l;
   int y=m+1;
   int z=0;

   while(x<= m && y<= r){
       if(arr[x]>arr[y]){
           ans[z]=arr[y];
           z++;
           y++;
       }
       else{
           ans[z]=arr[x];
           z++;
           x++;
       }
   }
   while(x<= m){
       ans[z]=arr[x];
       x++;
       z++;
   }
   while(y<= r){
       ans[z]=arr[y];
       y++;
       z++;
   }

   for(int k=l;k<= r;k++){
       arr[k]=ans[k-l];
   }
   delete []ans ;

}