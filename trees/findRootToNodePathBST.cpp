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

vector<int> *getPath(Node *root, int data)
{
    // Write your code here
    if (root == NULL)
    {
        vector<int> *path = new vector<int>();
        return path;
    }
    if (root->data == data)
    {
        vector<int> *path = new vector<int>();
        path->push_back(data);
        return path;
    }
    if (data < root->data)
    {
        vector<int> *pathFromLeft = getPath(root->left, data);
        if (pathFromLeft->size() > 0)
        {
            pathFromLeft->push_back(root->data);
            return pathFromLeft;
        }
    }
    else
    {
        vector<int> *pathFromRight = getPath(root->right, data);
        if (pathFromRight->size() > 0)
        {
            pathFromRight->push_back(root->data);
            return pathFromRight;
        }
    }
    vector<int> *path = new vector<int>();
    return path;
}

int main()
{
    vector<int> arr1 = {50, 25, 75, 12, 37, 62, 87, -1, -1, 30, -1, -1, 70};
    Node *root1 = takeInput(arr1);
    vector<int> *path = getPath(root1, 30);
    for (auto i : *path)
    {
        cout << i << " ";
    }
    cout << endl;
    delete root1;
    delete path;
    return 0;
}