#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        delete next;
    }
};

Node *takeInput(vector<int> &arr)
{
    Node *head = NULL, *tail = NULL;
    for (int i = 0; i < arr.size(); i++)
    {
        Node *newNode = new Node(arr[i]);
        if (head == NULL && tail == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

void printLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int lengthLL(Node *head)
{
    if (head == NULL)
        return 0;
    return lengthLL(head->next) + 1;
}

Node *mergeSortedLLs(Node *head1, Node *head2)
{
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;
    Node *finalHead = NULL, *finalTail = NULL;
    Node *temp1 = head1, *temp2 = head2;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data <= temp2->data)
        {
            if (finalHead == NULL && finalTail == NULL)
            {
                finalHead = temp1;
                finalTail = temp1;
            }
            else
            {
                finalTail->next = temp1;
                finalTail = temp1;
            }
            temp1 = temp1->next;
        }
        else
        {
            if (finalHead == NULL && finalTail == NULL)
            {
                finalHead = temp2;
                finalTail = temp2;
            }
            else
            {
                finalTail->next = temp2;
                finalTail = temp2;
            }
            temp2 = temp2->next;
        }
    }
    while (temp1 != NULL)
    {
        finalTail->next = temp1;
        finalTail = temp1;
        temp1 = temp1->next;
    }
    while (temp2 != NULL)
    {
        finalTail->next = temp2;
        finalTail = temp2;
        temp2 = temp2->next;
    }
    return finalHead;
}

int main()
{
    vector<int> arr1 = {0, 2, 4, 6, 8};
    Node *head1 = takeInput(arr1);
    vector<int> arr2 = {1, 3, 5, 7, 9};
    Node *head2 = takeInput(arr2);
    Node *head3 = mergeSortedLLs(head1, head2);
    printLL(head3);
    delete head1;
    delete head2;
    delete head3;
    return 0;
}