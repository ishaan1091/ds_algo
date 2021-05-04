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

Node *constructBinaryTree(int postorder[], int postorderSize, int inorder[], int inorderSize)
{
    if (postorderSize == 0 || inorderSize == 0)
        return NULL;
    Node *root = new Node(postorder[postorderSize - 1]);
    int rootInorderIndex;
    for (int i = 0; i < inorderSize; i++)
    {
        if (inorder[i] == postorder[postorderSize - 1])
        {
            rootInorderIndex = i;
            break;
        }
    }
    int leftInorderStart = 0, leftInorderEnd = rootInorderIndex - 1, leftpostorderStart = 0, leftpostorderEnd = rootInorderIndex - 1, leftLength = rootInorderIndex;
    int rightInorderStart = rootInorderIndex + 1, rightInorderEnd = inorderSize - 1, rightpostorderStart = leftpostorderEnd + 1, rightpostorderEnd = postorderSize - 2, rightLength = postorderSize - leftLength - 1;
    Node *leftChild = constructBinaryTree(postorder + leftpostorderStart, leftLength, inorder + leftInorderStart, leftLength);
    Node *rightChild = constructBinaryTree(postorder + rightpostorderStart, rightLength, inorder + rightInorderStart, rightLength);
    root->left = leftChild;
    root->right = rightChild;
    return root;
}

int main()
{
    int arr1[] = {2, 9, 3, 6, 10, 5};
    int arr2[] = {2, 6, 3, 9, 5, 10};
    Node *root1 = constructBinaryTree(arr1, 6, arr2, 6);
    levelorderLinewise(root1);
    delete root1;
    return 0;
}