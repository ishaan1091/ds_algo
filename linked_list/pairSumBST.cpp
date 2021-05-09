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

void inorderTraversal(Node *root, vector<int> &inorder)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left, inorder);
    inorder.push_back(root->data);
    inorderTraversal(root->right, inorder);
}

void pairSum1(Node *root, int s)
{
    // Write your code here
    if (root == NULL)
        return;
    vector<int> inorder;
    inorderTraversal(root, inorder);

    int i = 0, j = inorder.size() - 1;
    while (i < j)
    {
        if (inorder[i] + inorder[j] == s)
        {
            cout << inorder[i] << " " << inorder[j] << endl;
            i++;
            j--;
        }
        else if (inorder[i] + inorder[j] > s)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
}

Node *getNextFromInorder(stack<pair<Node *, int>> &s)
{
    while (s.size() > 0)
    {
        pair<Node *, int> top = s.top();
        if (top.second == 0)
        {
            s.top().second++;
            if (top.first->left)
                s.push(make_pair(top.first->left, 0));
        }
        else if (top.second == 1)
        {
            s.top().second++;
            if (top.first->right)
                s.push(make_pair(top.first->right, 0));
            return top.first;
        }
        else
        {
            s.pop();
        }
    }
    return NULL;
}

Node *getNextFromReverseInorder(stack<pair<Node *, int>> &s)
{
    while (s.size() > 0)
    {
        pair<Node *, int> top = s.top();
        if (top.second == 0)
        {
            s.top().second++;
            if (top.first->right)
                s.push(make_pair(top.first->right, 0));
        }
        else if (top.second == 1)
        {
            s.top().second++;
            if (top.first->left)
                s.push(make_pair(top.first->left, 0));
            return top.first;
        }
        else
        {
            s.pop();
        }
    }
    return NULL;
}

void pairSum2(Node *root, int s)
{
    if (root == NULL)
        return;
    stack<pair<Node *, int>> leftStack;
    stack<pair<Node *, int>> rightStack;
    leftStack.push(make_pair(root, 0));
    rightStack.push(make_pair(root, 0));
    Node *left = getNextFromInorder(leftStack);
    Node *right = getNextFromReverseInorder(rightStack);
    while (left && right && left->data < right->data)
    {
        if (left->data + right->data < s)
        {
            left = getNextFromInorder(leftStack);
        }
        else if (left->data + right->data > s)
        {
            right = getNextFromReverseInorder(rightStack);
        }
        else
        {
            cout << left->data << " " << right->data << endl;
            left = getNextFromInorder(leftStack);
            right = getNextFromReverseInorder(rightStack);
        }
    }
}

int main()
{
    vector<int> arr1 = {4, 2, 6, 1, 3, 5, 7};
    Node *root1 = takeInput(arr1);
    pairSum1(root1, 8);
    cout << endl;
    pairSum1(root1, 8);
    delete root1;
    return 0;
}