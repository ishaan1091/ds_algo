#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    vector<Node *> children;
    Node(int data)
    {
        this->data = data;
    }
    ~Node()
    {
        for (int i = 0; i < children.size(); i++)
        {
            delete children[i];
        }
    }
};

Node *takeInput(vector<int> &arr)
{
    stack<Node *> s;
    Node *root = new Node(0);
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == -1)
        {
            s.pop();
        }
        else
        {
            Node *temp = new Node(arr[i]);
            if (s.size() == 0)
            {
                root = temp;
            }
            else
            {
                s.top()->children.push_back(temp);
            }
            s.push(temp);
        }
    }
    return root;
}

void display(Node *root)
{
    queue<Node *> mq;
    mq.push(root);
    queue<Node *> cq;
    while (!mq.empty())
    {
        Node *front = mq.front();
        mq.pop();
        cout << front->data << " ";
        for (auto i : front->children)
        {
            cq.push(i);
        }
        if (mq.size() == 0)
        {
            queue<Node *> temp;
            mq = cq;
            cq = temp;
            cout << endl;
        }
    }
}

Node *getTail(Node *root)
{
    while (root->children.size() == 1)
    {
        root = root->children[0];
    }
    return root;
}

void linearizeTree1(Node *root)
{
    for (auto i : root->children)
    {
        linearizeTree1(i);
    }
    while (root->children.size() > 1)
    {
        Node *last = root->children[root->children.size() - 1];
        root->children.pop_back();
        Node *secondLast = root->children[root->children.size() - 1];
        Node *tail = getTail(secondLast);
        tail->children.push_back(last);
    }
}

Node *linearizeTree2(Node *root)
{
    Node *ans = root;
    for (int i = root->children.size() - 1; i >= 0; i--)
    {
        Node *tail = linearizeTree2(root->children[i]);
        if (i < root->children.size() - 1)
        {
            tail->children.push_back(root->children[i + 1]);
            root->children.pop_back();
        }
        else
        {
            ans = tail;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr1 = {10, 20, -1, 30, 50, -1, 60, -1, -1, 40, -1};
    vector<int> arr2 = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1};
    Node *root1 = takeInput(arr1);
    Node *root2 = takeInput(arr2);
    display(root2);
    linearizeTree1(root2);
    display(root2);
    root2 = takeInput(arr2);
    cout << endl;
    linearizeTree2(root2);
    display(root2);
    delete root1;
    delete root2;
    return 0;
}