#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    ~Node()
    {
        delete left;
        delete right;
    }
};

void display(Node *root)
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

Node *takeInput(vector<int> &arr)
{
    queue<Node *> q;
    Node *root = new Node(arr[0]);
    q.push(root);
    int index = 1;
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (arr[index] != -1)
        {
            front->left = new Node(arr[index]);
            q.push(front->left);
        }
        index++;
        if (index == arr.size())
            break;
        if (arr[index] != -1)
        {
            front->right = new Node(arr[index]);
            q.push(front->right);
        }
        index++;
        if (index == arr.size())
            break;
    }
    return root;
}

void levelorderLinewise(Node *root)
{
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));
    int level = 0;
    while (!q.empty())
    {
        pair<Node *, int> front = q.front();
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

void inorderTraversal(Node *root, vector<int> &traversal)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left, traversal);
    traversal.push_back(root->data);
    inorderTraversal(root->right, traversal);
}

void BSTToMinHeapUtil(Node *root, vector<int> &traversal, int &index)
{
    if (root == NULL)
        return;
    root->data = traversal[index++];
    BSTToMinHeapUtil(root->left, traversal, index);
    BSTToMinHeapUtil(root->right, traversal, index);
}

void convertBSTToMinHeap(Node *root)
{
    vector<int> traversal;
    inorderTraversal(root, traversal);
    int index = 0;
    BSTToMinHeapUtil(root, traversal, index);
}

int main()
{
    vector<int> arr1 = {4, 2, 6, 1, 3, 5, 7};
    Node *root1 = takeInput(arr1);
    convertBSTToMinHeap(root1);
    display(root1);
    levelorderLinewise(root1);
    delete root1;
    return 0;
}