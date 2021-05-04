#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    ~BinaryTreeNode()
    {
        delete left;
        delete right;
    }
};

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node(T data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        delete next;
    }
};

void display(BinaryTreeNode<int> *root)
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

BinaryTreeNode<int> *takeInput(vector<int> &arr)
{
    queue<BinaryTreeNode<int> *> q;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(arr[0]);
    q.push(root);
    int index = 1;
    while (!q.empty())
    {
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        if (arr[index] != -1)
        {
            front->left = new BinaryTreeNode<int>(arr[index]);
            q.push(front->left);
        }
        index++;
        if (index == arr.size())
            break;
        if (arr[index] != -1)
        {
            front->right = new BinaryTreeNode<int>(arr[index]);
            q.push(front->right);
        }
        index++;
        if (index == arr.size())
            break;
    }
    return root;
}

void levelorderLinewise(BinaryTreeNode<int> *root)
{
    queue<pair<BinaryTreeNode<int> *, int>> q;
    q.push(make_pair(root, 0));
    int level = 0;
    while (!q.empty())
    {
        pair<BinaryTreeNode<int> *, int> front = q.front();
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

vector<Node<int> *> constructLinkedListForEachLevel(BinaryTreeNode<int> *root)
{
    vector<Node<int> *> output;
    if (root == NULL)
        return output;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    Node<int> *currentLevelHead = NULL;
    Node<int> *currentLevelTail = NULL;
    while (!q.empty())
    {
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        if (front == NULL)
        {
            if (q.size() == 0)
            {
                output.push_back(currentLevelHead);
                currentLevelHead = NULL;
                currentLevelTail = NULL;
                continue;
            }
            output.push_back(currentLevelHead);
            currentLevelHead = NULL;
            currentLevelTail = NULL;
            q.push(NULL);
            continue;
        }
        Node<int> *newNode = new Node<int>(front->data);
        if (currentLevelHead == NULL)
        {
            currentLevelHead = newNode;
            currentLevelTail = newNode;
        }
        else
        {
            currentLevelTail->next = newNode;
            currentLevelTail = newNode;
        }
        if (front->left)
            q.push(front->left);
        if (front->right)
            q.push(front->right);
    }
    return output;
}

void printLL(vector<Node<int> *> &treeLevels)
{
    for (auto i : treeLevels)
    {
        while (i != NULL)
        {
            cout << i->data << " ";
            i = i->next;
        }
        cout << endl;
    }
}

int main()
{
    vector<int> arr1 = {50, 25, 75, 12, 37, 62, 87, -1, -1, 30, -1, -1, 70};
    BinaryTreeNode<int> *root1 = takeInput(arr1);
    vector<Node<int> *> output = constructLinkedListForEachLevel(root1);
    printLL(output);
    delete root1;
    return 0;
}