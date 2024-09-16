/*
Problem statement
You have been given a singly linked list of integers. Write a function 
to print the list in a reverse order.

To explain it further, you need to start printing the data from the tail and move 
towards the head of the list, printing the head data at the end.

Note :
You can’t change any of the pointers in the linked list, just print the linked list in the reverse order.
Detailed explanation ( Input/output format, Notes, Images )
 Constraints :
1 <= t <= 10^2
0 <= M <= 10^3


Time Limit: 1sec

Where 'M' is the size of the singly linked list.
Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the 
singly linked list and hence, would never be a list element.

Sample Input 1 :
1
1 2 3 4 5 -1
Sample Output 1 :
5 4 3 2 1
Sample Input 2 :
2
1 2 3 -1
10 20 30 40 50 -1
Sample Output 2 :
3 2 1
50 40 30 20 10

*/
#include<bits/stdc++.h>
using namespace std;
#include"LinkedListClass.C++"

#include <vector>
void printReverse(Node *head){
	if(head==NULL){
		return;
	}
	vector<int> arr;
	Node* temp=head;
	while(temp!=NULL){
		arr.push_back(temp->data);
		temp=temp->next;
	}
	int n=arr.size();
	for(int i=n-1;i>=0;i--){
		cout<<arr[i]<<" ";
	}
}
