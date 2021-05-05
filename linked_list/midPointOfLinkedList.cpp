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

Node *midPoint(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main()
{
    vector<int> arr1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node *head1 = takeInput(arr1);
    printLL(head1);
    Node *midPoint1 = midPoint(head1);
    cout << midPoint1->data << endl;
    vector<int> arr2 = {0, 1, 2, 3, 4, 5, 6};
    Node *head2 = takeInput(arr2);
    printLL(head2);
    Node *midPoint2 = midPoint(head2);
    cout << midPoint2->data << endl;
    delete head1;
    delete head2;
    return 0;
}