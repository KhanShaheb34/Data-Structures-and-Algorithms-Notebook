#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
// iterative approach
node *reverse(node *&head)
{
    node *prevPtr = NULL;
    node *currPtr = head;
    node *nextPtr;
    while (currPtr != NULL)
    {
        nextPtr = currPtr->next;
        currPtr->next = prevPtr;
        prevPtr = currPtr;
        currPtr = nextPtr;
    }
    return prevPtr; // new head
}

// recursive approach
node *reverseRecursive(node *&head)
{
    // base condition
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *newHead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}

node *reverseK(node *&head, int k)
{
    node *prevPtr = NULL;
    node *currPtr = head;
    node *nextPtr;
    int count = 0;
    while (currPtr != NULL && count < k)
    {
        nextPtr = currPtr->next;
        currPtr->next = prevPtr;
        prevPtr = currPtr;
        currPtr = nextPtr;

        count++;
    } // k nodes

    if (nextPtr != NULL)
    {
        head->next = reverseK(nextPtr, k);
    }
    return prevPtr;
}
void insertAtTail(node *&head, int val)
{
    node *newNode = new node(val); // created a  new node;
    if (head == NULL)
    {
        head = newNode;
        return;
        // here you can simply call insertAtBeginning
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    // as our new node already points to NULL in its next so we simply do nothing
}

void display(node *head)
{
    if (head == NULL)
    {
        cout << "NULL" << endl;
        return;
    }
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 23);
    insertAtTail(head, 12);
    insertAtTail(head, 10);
    display(head);
    int k = 2;
    node *newHead = reverseK(head, k);
    display(newHead);
}
