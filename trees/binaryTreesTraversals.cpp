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

void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void levelorder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        cout << front->data << " ";
        if (front->left)
            q.push(front->left);
        if (front->right)
            q.push(front->right);
    }
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

void iterativeTraversals(Node *root)
{
    stack<pair<Node *, int>> s;
    s.push(make_pair(root, 0));
    string pre = "";
    string in = "";
    string post = "";
    while (!s.empty())
    {
        pair<Node *, int> top = s.top();
        if (top.second == 0)
        {
            pre += to_string(top.first->data) + " ";
            s.top().second++;
            if (top.first->left)
            {
                s.push(make_pair(top.first->left, 0));
            }
        }
        else if (top.second == 1)
        {
            in += to_string(top.first->data) + " ";
            s.top().second++;
            if (top.first->right)
            {
                s.push(make_pair(top.first->right, 0));
            }
        }
        else
        {
            post += to_string(top.first->data) + " ";
            s.pop();
        }
    }
    cout << "    PRE : " << pre << endl;
    cout << "    IN : " << in << endl;
    cout << "    POST : " << post << endl;
}

int main()
{
    vector<int> arr1 = {50, 25, 75, 12, 37, 62, 87, -1, -1, 30, -1, -1, 70};
    Node *root1 = takeInput(arr1);
    cout << "PREORDER : " << endl;
    preorder(root1);
    cout << endl;
    cout << "INORDER : " << endl;
    inorder(root1);
    cout << endl;
    cout << "POSTORDER : " << endl;
    postorder(root1);
    cout << endl;
    cout << "LEVELORDER : " << endl;
    levelorder(root1);
    cout << endl;
    cout << "LEVELORDER LINEWISE : " << endl;
    levelorderLinewise(root1);
    cout << endl;
    cout << "ITERATIVE PRE POST IN TRAVERSAL : " << endl;
    iterativeTraversals(root1);
    cout << endl;
    delete root1;
    return 0;
}