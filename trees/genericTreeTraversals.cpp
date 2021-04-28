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

Node *takeInputLevelwise(vector<int> &arr)
{
    Node *root = new Node(arr[0]);
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        cout << "Enter the number of chilren of " << front->data << " : ";
        int num;
        cin >> num;
        for (int i = 0; i < num; i++)
        {
            int child;
            cout << "Enter " << i << "th child data : ";
            cin >> child;
            Node *childNode = new Node(child);
            front->children.push_back(childNode);
            q.push(childNode);
        }
    }
    return root;
}

void traversal(Node *root)
{
    cout << "Node Pre " << root->data << endl;
    for (auto i : root->children)
    {
        cout << "Edge Pre " << root->data << " -- " << i->data << endl;
        traversal(i);
        cout << "Edge Post " << root->data << " -- " << i->data << endl;
    }
    cout << "Node Post " << root->data << endl;
}

void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        cout << front->data << " ";
        for (auto i : front->children)
        {
            q.push(i);
        }
    }
    cout << endl;
}

void levelOrderLinewiseTraversal1(Node *root)
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

void levelOrderZigZagTraversal(Node *root)
{
    stack<Node *> ms;
    stack<Node *> cs;
    ms.push(root);
    int level = 0;
    while (!ms.empty())
    {
        Node *top = ms.top();
        ms.pop();
        cout << top->data << " ";
        if (level % 2 == 0)
        {
            for (auto i : top->children)
            {
                cs.push(i);
            }
        }
        else
        {
            for (int i = top->children.size() - 1; i >= 0; i--)
            {
                cs.push(top->children[i]);
            }
        }
        if (ms.size() == 0)
        {
            stack<Node *> temp;
            ms = cs;
            cs = temp;
            level++;
            cout << endl;
        }
    }
}

void levelOrderLinewiseTraversal2(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();
        if (front != NULL)
        {
            cout << front->data << " ";
            for (auto i : front->children)
            {
                q.push(i);
            }
        }
        else
        {
            if (q.size() > 0)
            {
                q.push(NULL);
                cout << endl;
            }
        }
    }
    cout << endl;
}

void levelOrderLinewiseTraversal3(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++)
        {
            Node *front = q.front();
            q.pop();
            cout << front->data << " ";
            for (auto j : front->children)
            {
                q.push(j);
            }
        }
        cout << endl;
    }
}

void levelOrderLinewiseTraversal4(Node *root)
{
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 1));
    int level = 1;
    while (!q.empty())
    {
        pair<Node *, int> p = q.front();
        q.pop();
        if (p.second > level)
        {
            level = p.second;
            cout << endl;
        }
        cout << p.first->data << " ";
        for (auto i : p.first->children)
        {
            q.push(make_pair(i, p.second + 1));
        }
    }
    cout << endl;
}

int main()
{
    vector<int> arr1 = {10, 20, -1, 30, 50, -1, 60, -1, -1, 40, -1};
    vector<int> arr2 = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1};
    Node *root1 = takeInput(arr1);
    Node *root2 = takeInput(arr2);
    traversal(root1);
    levelOrderTraversal(root1);
    cout << endl;
    levelOrderLinewiseTraversal1(root1);
    cout << endl;
    levelOrderZigZagTraversal(root1);
    cout << endl;
    levelOrderZigZagTraversal(root2);
    cout << endl;
    levelOrderLinewiseTraversal2(root1);
    cout << endl;
    levelOrderLinewiseTraversal3(root1);
    cout << endl;
    levelOrderLinewiseTraversal4(root1);
    cout << endl;
    delete root1;
    delete root2;
    return 0;
}