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

void treetoarray(Node *root, vector<int> &output)
{

    if (root == NULL)
    {
        return;
    }

    output.push_back(root->data);
    treetoarray(root->left, output);
    treetoarray(root->right, output);
}

void pairSum(Node *root, int s)
{
    // Write your code here

    vector<int> output;
    treetoarray(root, output);

    unordered_map<int, int> map;
    for (auto i : output)
    {
        if (map.count(i) != 0)
        {
            map[i] = 1;
        }
        else
        {
            map[i]++;
        }
    }
    unordered_map<int, int>::iterator it = map.begin();
    while (it != map.end())
    {
        if (it->second != INT_MIN)
        {
            if (map.count(s - it->first) != 0 && map[s - it->first] != INT_MIN && it->first != s - it->first)
            {
                cout << min(it->first, s - it->first) << " " << max(it->first, s - it->first) << endl;
                map[s - it->first] = INT_MIN;
            }
        }
        it++;
    }
}

int main()
{
    vector<int> arr1 = {1, 2, 2, 3, 4, 5, 6, 6, 7};
    Node *root1 = takeInput(arr1);
    pairSum(root1, 8);
    delete root1;
    return 0;
}