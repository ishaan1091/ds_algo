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

vector<int> nodeToRootPath(Node *root, int val)
{
    if (root->data == val)
    {
        vector<int> ans;
        ans.push_back(root->data);
        return ans;
    }
    for (auto i : root->children)
    {
        vector<int> ans = nodeToRootPath(i, val);
        if (ans.size() > 0)
        {
            ans.push_back(root->data);
            return ans;
        }
    }
    vector<int> ans;
    return ans;
}

int lca(Node *root, int val1, int val2)
{
    vector<int> path1 = nodeToRootPath(root, val1);
    vector<int> path2 = nodeToRootPath(root, val2);
    int i = path1.size() - 1;
    int j = path2.size() - 1;
    while (i >= 0 && j >= 0 && path1[i] == path2[j])
    {
        i--;
        j--;
    }
    i++;
    j++;
    return path1[i];
}

int main()
{
    vector<int> arr1 = {10, 20, -1, 30, 50, -1, 60, -1, -1, 40, -1};
    vector<int> arr2 = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1};
    Node *root1 = takeInput(arr1);
    Node *root2 = takeInput(arr2);
    int ans = lca(root2, 110, 70);
    cout << ans << endl;
    ans = lca(root2, 110, 120);
    cout << ans << endl;
    delete root1;
    delete root2;
    return 0;
}