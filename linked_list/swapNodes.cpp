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

Node *swapNodes(Node *head, int i, int j)
{
    //Write your code here
    if (i == j)
        return head;
    Node *temp = head, *temp11 = NULL, *temp12 = NULL, *temp21 = NULL, *temp22 = NULL;
    int count = 0;
    while (temp != NULL)
    {
        if (count == i - 1)
            temp11 = temp;
        if (count == i)
            temp12 = temp;
        if (count == j - 1)
            temp21 = temp;
        if (count == j)
            temp22 = temp;
        count++;
        temp = temp->next;
    }
    if (!temp12 || !temp22)
        return head;
    else if (temp11 == NULL)
    {
        temp21->next = temp12;
        temp12->next = temp22->next;
        temp22->next = head->next;
        head = temp22;
        return head;
    }
    else if (temp21 == NULL)
    {
        temp11->next = temp22;
        temp22->next = temp12->next;
        temp12->next = head->next;
        head = temp12;
        return head;
    }
    else
    {
        temp11->next = temp22;
        temp21->next = temp12;
        temp = temp22->next;
        temp22->next = temp12->next;
        temp12->next = temp;
        return head;
    }
}

int main()
{
    vector<int> arr1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node *head1 = takeInput(arr1);
    printLL(head1);
    head1 = swapNodes(head1, 4, 3);
    printLL(head1);
    delete head1;
    return 0;
}