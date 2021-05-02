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

void printKLevelsDown(Node *root, int k, Node *blocker)
{
    if (root == NULL || root == blocker)
        return;
    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }
    printKLevelsDown(root->left, k - 1, blocker);
    printKLevelsDown(root->right, k - 1, blocker);
}

void findPath(Node *root, int val, vector<Node *> &path)
{
    if (root == NULL)
        return;
    if (root->data == val)
    {
        path.push_back(root);
        return;
    }
    findPath(root->left, val, path);
    if (path.size() > 0)
    {
        path.push_back(root);
        return;
    }
    findPath(root->right, val, path);
    if (path.size() > 0)
    {
        path.push_back(root);
        return;
    }
}

void printKLevelsFar(Node *root, int val, int k)
{
    vector<Node *> path;
    findPath(root, val, path);
    for (int i = 0; i < path.size() && i <= k; i++)
    {
        printKLevelsDown(path[i], k - i, i == 0 ? NULL : path[i - 1]);
    }
}

int main()
{
    vector<int> arr1 = {50, 25, 75, 12, 37, 62, 87, -1, -1, 30, -1, -1, 70};
    Node *root1 = takeInput(arr1);
    printKLevelsFar(root1, 37, 2);
    delete root1;
    return 0;
}