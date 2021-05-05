#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        delete next;
    }
};

void display(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    if (root->left)
    {
        cout << root->left->data << " - ";
    }
    else
    {
        cout << ". - ";
    }
    cout << root->data << " - ";
    if (root->right)
    {
        cout << root->right->data << endl;
    }
    else
    {
        cout << "." << endl;
    }
    display(root->left);
    display(root->right);
}

BinaryTreeNode<int> *takeInput(vector<int> &arr)
{
    queue<BinaryTreeNode<int> *> q;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(arr[0]);
    q.push(root);
    int index = 1;
    while (!q.empty())
    {
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        if (arr[index] != -1)
        {
            front->left = new BinaryTreeNode<int>(arr[index]);
            q.push(front->left);
        }
        index++;
        if (index == arr.size())
            break;
        if (arr[index] != -1)
        {
            front->right = new BinaryTreeNode<int>(arr[index]);
            q.push(front->right);
        }
        index++;
        if (index == arr.size())
            break;
    }
    return root;
}

void levelorderLinewise(BinaryTreeNode<int> *root)
{
    queue<pair<BinaryTreeNode<int> *, int>> q;
    q.push(make_pair(root, 0));
    int level = 0;
    while (!q.empty())
    {
        pair<BinaryTreeNode<int> *, int> front = q.front();
        q.pop();
        if (front.second > level)
        {
            cout << endl;
            level = front.second;
        }
        cout << front.first->data << " ";
        if (front.first->left)
            q.push(make_pair(front.first->left, front.second + 1));
        if (front.first->right)
            q.push(make_pair(front.first->right, front.second + 1));
    }
    cout << endl;
}

Node<int> *constructLinkedList(BinaryTreeNode<int> *root)
{
    // Write your code here
    if (root == NULL)
        return NULL;
    Node<int> *left = constructLinkedList(root->left);
    Node<int> *right = constructLinkedList(root->right);
    Node<int> *rootNode = new Node<int>(root->data);
    Node<int> *head = rootNode;
    if (left)
    {
        Node<int> *temp = left;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = rootNode;
        head = left;
    }
    rootNode->next = right;
    return head;
}

void printLL(Node<int> *head)
{
    Node<int> *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    vector<int> arr1 = {50, 25, 75, 12, 37, 62, 87, -1, -1, 30, -1, -1, 70};
    BinaryTreeNode<int> *root1 = takeInput(arr1);
    Node<int> *output = constructLinkedList(root1);
    printLL(output);
    delete root1;
    return 0;
}