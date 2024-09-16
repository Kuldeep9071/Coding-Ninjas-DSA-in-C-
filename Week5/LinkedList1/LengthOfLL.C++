#include<bits/stdc++.h>
using namespace std;
#include"LinkedListClass.C++"

int length(Node *head)
{
    Node *temp = head;
    int length = 0;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}
