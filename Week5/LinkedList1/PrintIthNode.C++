#include<bits/stdc++.h>
using namespace std;
#include"LinkedListClass.C++"

void printIthNode(Node *head, int i)
{
    if (head == NULL)
    {
        return;
    }
    Node *temp = head;
    while (i-- && temp != NULL)
    {
        temp = temp->next;
    }
    if (temp != NULL)
        cout << temp->data;
}