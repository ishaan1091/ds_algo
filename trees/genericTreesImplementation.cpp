#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    vector<Node *> children;
    Node(int data)
    {
        this->val = data;
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
    cout << root->val << " => ";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->val << " ";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        display(root->children[i]);
    }
}

int sizeOfTree(Node *root)
{
    int ans = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        int childAns = sizeOfTree(root->children[i]);
        ans += childAns;
    }
    ans++;
    return ans;
}

int maxOfTree(Node *root)
{
    int ans = INT_MIN;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans = max(ans, maxOfTree(root->children[i]));
    }
    return max(root->val, ans);
}

int height(Node *root)
{
    int ans = -1;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans = max(ans, height(root->children[i]));
    }
    ans++;
    return ans;
}

int main()
{
    vector<int> arr = {10, 20, 50, -1, 60, -1, -1, 30, 70, -1, 80, 110, -1, 120, -1, -1, 90, -1, -1, 40, 100, -1, -1, -1};
    Node *root = takeInput(arr);
    display(root);
    int ans = sizeOfTree(root);
    cout << endl
         << "Size of Tree : " << ans << endl;
    ans = maxOfTree(root);
    cout << endl
         << "Max Element of the Tree : " << ans << endl;
    ans = height(root);
    cout << endl
         << "Height of Tree : " << ans << endl;
    delete root;
    return 0;
}