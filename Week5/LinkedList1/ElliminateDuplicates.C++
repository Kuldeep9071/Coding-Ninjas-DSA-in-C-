/*Problem statement
You have been given a singly linked list of integers where the elements are sorted 
in ascending order. Write a function that removes the consecutive duplicate values
 such that the given list only contains unique elements and returns the head to the updated list.

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= t <= 10^2
0 <= M <= 10^5
Time Limit: 1sec

Where 'M' is the size of the singly linked list.
 Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list
 and hence, would never be a list element.
Sample Input 1 :
1
1 2 3 3 3 3 4 4 4 5 5 7 -1
Sample Output 1 :
1 2 3 4 5 7 
Sample Input 2 :
2
10 20 30 40 50 -1
10 10 10 10 -1
Sample Output 2 :
10 20 30 40 50
10

*/

#include<bits/stdc++.h>
using namespace std;
#include"LinkedListClass.C++"

Node *removeDuplicates(Node *head){
	if(head==NULL || head->next==NULL){
		return head;
	}

	Node* temp=head;

	while((temp->next)!=NULL){
		if(temp->data==(temp->next)->data){
			Node* a=temp->next;
			Node* b=(temp->next)->next;
			temp->next=b;
			delete a;
		}
		else {
			temp = temp->next;
		}
	}
	return head;
}