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

bool isSibling(Node *root, int p, int q)
{
    if (root == NULL)
        return false;
    if (root->left == NULL || root->right == NULL)
        return isSibling(root->left, p, q) || isSibling(root->right, p, q);
    return (root->left->data == p && root->right->data == q) || (root->left->data == q && root->right->data == p) || isSibling(root->left, p, q) || isSibling(root->right, p, q);
}

int findLevel(Node *root, int val, int level = 0)
{
    if (root == NULL)
        return -1;
    if (root->data == val)
        return level;
    return (findLevel(root->left, val, level + 1) == -1 ? findLevel(root->right, val, level + 1) : findLevel(root->left, val, level + 1));
}

bool isCousin(Node *root, int p, int q)
{
    // Write your code here
    if (root == NULL)
        return false;
    if (findLevel(root, p) == findLevel(root, q) && !isSibling(root, p, q))
        return true;
    return false;
}

int main()
{
    vector<int> arr1 = {50, 25, 75, 12, 37, 62, 87, -1, -1, 30, -1, -1, 70};
    Node *root1 = takeInput(arr1);
    cout << (isCousin(root1, 87, 12) ? "YES" : "NO") << endl;
    cout << (isCousin(root1, 37, 12) ? "YES" : "NO") << endl;
    delete root1;
    return 0;
}