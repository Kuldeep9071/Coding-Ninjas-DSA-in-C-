/*
Problem statement
Given an unsorted array of integers, you have to move the array elements in a way such that all the zeroes are transferred to the end, and all the non-zero elements are moved to the front. Use the concept of dynamic memory allocation for taking array input.

All non zero element will remain in same order as before.

For example, if the input array is: [0, 1, -2, 3, 4, 0, 5, -27, 9, 0], then the output array must be:

[1, -2, 3, 4, 5, -27, 9, 0, 0, 0].

Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1:
2
7
2 0 4 1 3 0 28
5
0 0 0 0 1
Sample Output 1:
2 4 1 3 28 0 0
1 0 0 0 0
The explanation for Sample Output 1 :
In the first testcase, All the zeros are moved towards the end of the array, and the non-zero elements are pushed towards the left, maintaining their order with respect to the original array.

In the second testcase, All zero are moved towards the end, hence the only non-zero element i.e 1 is in the starting of the array 
Sample Input 2:
2
5
0 3 0 2 0
4
0 0 0 0
Sample Output 2:
3 2 0 0 0
0 0 0 0

*/

#include<iostream>
using namespace std;
int main(){
    int Testcase;
    cin>>Testcase;
    for(int x=0;x<Testcase;x++){
        int n;
        cin>>n;
        int *arr=new int[n];

        for(int g=0;g<n;g++){
            cin>>arr[g];
        }

        int i=0;
        while(i<n){
            if((arr[i])==0){ 
                int j=i+1;
                while(j<n){
                    arr[j-1]=arr[j];
                    j++;
                }
                arr[n-1]=0;
            }
            i++;
            bool b=true;
            for(int v=i;v<n;v++){
                if(arr[v]!=0){
                    b=false;
                    break;
                }
            }
            if(b==1){
                break;
            }
            else{
                if(arr[i-1]==0){
                    i--;
                }
            }
        }
        for(int k=0;k<n;k++){
            cout<<arr[k]<<" ";
        }
        cout<<endl;
        delete []arr;
    }
}