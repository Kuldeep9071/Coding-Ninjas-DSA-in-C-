#include<bits/stdc++.h>
using namespace std;
#include"LinkedListClass.C++"


int length(Node *head) {
	if(head==NULL){
		return 0;
	}
	else{
		return 1+length(head->next);
	}
}