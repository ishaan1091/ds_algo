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

bool findElement(Node *root, int val)
{
    if (root == NULL)
        return false;
    if (root->data == val)
        return true;
    for (auto i : root->children)
    {
        bool ans = findElement(i, val);
        if (ans)
            return ans;
    }
    return false;
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

int main()
{
    vector<int> arr1 = {10, 20, -1, 30, 50, -1, 60, -1, -1, 40, -1};
    vector<int> arr2 = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1};
    Node *root1 = takeInput(arr1);
    Node *root2 = takeInput(arr2);
    int val1 = 110;
    int val2 = 1100;
    int val3 = 20;
    bool ans = findElement(root2, val1);
    cout << val1 << " : " << (ans ? "YES" : "NO") << endl;
    ans = findElement(root2, val2);
    cout << val2 << " : " << (ans ? "YES" : "NO") << endl;
    ans = findElement(root2, val3);
    cout << val3 << " : " << (ans ? "YES" : "NO") << endl;
    vector<int> output = nodeToRootPath(root2, val1);
    for (auto i : output)
    {
        cout << i << " ";
    }
    cout << endl;
    delete root1;
    delete root2;
    return 0;
}