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

void printLLIterative(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void printLLRecursive(Node *head)
{
    if (head == NULL)
        return;
    cout << head->data << " ";
    printLLRecursive(head->next);
}

int lengthLLIterative(Node *head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

int lengthLLRecursive(Node *head)
{
    if (head == NULL)
        return 0;
    return lengthLLRecursive(head->next) + 1;
}

Node *insertLLIterative(Node *head, int pos, int data)
{
    int count = 0;
    Node *temp = head;
    if (pos == 0)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        return head;
    }
    while (temp != NULL && count < pos - 1)
    {
        count++;
        temp = temp->next;
    }
    Node *newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

Node *insertLLRecursive(Node *head, int pos, int data)
{
    if (head == NULL)
        return NULL;
    if (pos == 0)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        return head;
    }
    head->next = insertLLRecursive(head->next, pos - 1, data);
    return head;
}

Node *deleteLLIterative(Node *head, int pos)
{
    int count = 0;
    Node *temp = head;
    if (pos == 0)
    {
        head = head->next;
        delete temp;
        return head;
    }
    while (temp != NULL && count < pos - 1)
    {
        count++;
        temp = temp->next;
    }
    Node *deleteNode = temp->next;
    temp->next = temp->next->next;
    deleteNode->next = NULL;
    delete deleteNode;
    return head;
}

Node *deleteLLRecursive(Node *head, int pos)
{
    if (head == NULL)
        return NULL;
    if (pos == 0)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return head;
    }
    head->next = deleteLLRecursive(head->next, pos - 1);
    return head;
}

int findLLIterative(Node *head, int val)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == val)
            return count;
        temp = temp->next;
        count++;
    }
    return -1;
}

int findLLRecursive(Node *head, int val)
{
    if (head == NULL)
        return -1;
    if (head->data == val)
        return 0;
    int ans = findLLRecursive(head->next, val);
    return (ans == -1 ? -1 : ans + 1);
}

int main()
{
    vector<int> arr1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node *head1 = takeInput(arr1);
    printLLIterative(head1);
    printLLRecursive(head1);
    cout << endl;
    cout << lengthLLIterative(head1) << endl;
    cout << lengthLLRecursive(head1) << endl;
    head1 = insertLLIterative(head1, 6, 10);
    printLLIterative(head1);
    head1 = deleteLLIterative(head1, 6);
    printLLIterative(head1);
    head1 = insertLLRecursive(head1, 6, 10);
    printLLRecursive(head1);
    cout << endl;
    head1 = deleteLLRecursive(head1, 6);
    printLLRecursive(head1);
    cout << endl;
    cout << findLLIterative(head1, 6) << endl;
    cout << findLLIterative(head1, 11) << endl;
    cout << findLLRecursive(head1, 6) << endl;
    cout << findLLRecursive(head1, 11) << endl;
    delete head1;
    return 0;
}