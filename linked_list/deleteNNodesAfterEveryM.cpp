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

Node *skipMdeleteN(Node *head, int M, int N)
{
    // Write your code here
    if (M == 0)
    {
        return NULL;
    }
    if (N == 0)
        return head;
    Node *t1 = head;
    Node *t2 = head;
    while (t1 != NULL && t2 != NULL)
    {
        for (int i = 1; i < M && t1->next != NULL; i++)
        {
            t1 = t1->next;
        }
        t2 = t1->next;
        for (int i = 0; i < N && t2 != NULL; i++)
        {
            Node *temp = t2;
            t2 = t2->next;
            temp->next = NULL;
            delete temp;
        }
        t1->next = t2;
        t1 = t1->next;
    }
    return head;
}

int main()
{
    vector<int> arr1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node *head1 = takeInput(arr1);
    printLL(head1);
    head1 = skipMdeleteN(head1, 2, 1);
    printLL(head1);
    delete head1;
    return 0;
}