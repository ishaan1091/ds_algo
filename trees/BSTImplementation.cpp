#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }

    ~Node()
    {
        delete left;
        delete right;
    }
};

class BST
{
public:
    Node *root;

    BST(Node *root)
    {
        this->root = root;
    }

    ~BST()
    {
        delete this->root;
    }

    bool search(int val)
    {
        return searchUtil(this->root, val);
    }

    void insert(int val)
    {
        this->root = insertUtil(this->root, val);
    }

    void remove(int val)
    {
        this->root = removeUtil(this->root, val);
    }

    void print()
    {
        printUtil(this->root);
    }

    int size()
    {
        return sizeUtil(this->root);
    }

    int sum()
    {
        return sumUtil(this->root);
    }

    int maxVal()
    {
        return maxValUtil(this->root);
    }

    int minVal()
    {
        return minValUtil(this->root);
    }

    int height()
    {
        return heightUtil(this->root);
    }

    int diameter()
    {
        pair<int, int> ans = diameterUtil(this->root);
        return ans.second;
    }

private:
    bool searchUtil(Node *root, int val)
    {
        if (root == NULL)
            return false;
        if (root->val == val)
            return true;
        else if (root->val < val)
            return searchUtil(root->right, val);
        else
            return searchUtil(root->left, val);
    }

    Node *insertUtil(Node *root, int val)
    {
        if (root == NULL)
        {
            Node *newNode = new Node(val);
            return newNode;
        }
        if (root->val >= val)
        {
            root->left = insertUtil(root->left, val);
        }
        else
        {
            root->right = insertUtil(root->right, val);
        }
        return root;
    }

    Node *removeUtil(Node *root, int val)
    {
        if (root == NULL)
            return NULL;
        if (root->val > val)
        {
            root->left = removeUtil(root->left, val);
        }
        else if (root->val < val)
        {
            root->right = removeUtil(root->right, val);
        }
        else
        {
            if (root->left && root->right)
            {
                int leftMax = maxValUtil(root->left);
                root->val = leftMax;
                root->left = removeUtil(root->left, leftMax);
                return root;
            }
            else if (root->left)
            {
                Node *temp = root->left;
                root->left = NULL;
                delete root;
                return temp;
            }
            else if (root->right)
            {
                Node *temp = root->right;
                root->right = NULL;
                delete root;
                return temp;
            }
            else
            {
                delete root;
                return NULL;
            }
        }
        return root;
    }

    void printUtil(Node *root)
    {
        if (root == NULL)
            return;
        if (root->left)
        {
            cout << root->left->val << " ";
        }
        else
        {
            cout << ". ";
        }
        cout << root->val << " ";
        if (root->right)
        {
            cout << root->right->val << endl;
        }
        else
        {
            cout << "." << endl;
        }
        printUtil(root->left);
        printUtil(root->right);
    }

    int sizeUtil(Node *root)
    {
        if (root == NULL)
            return 0;
        int ans = 1;
        ans += sizeUtil(root->left);
        ans += sizeUtil(root->right);
        return ans;
    }

    int sumUtil(Node *root)
    {
        if (root == NULL)
            return 0;
        int ans = root->val;
        ans += sumUtil(root->left);
        ans += sumUtil(root->right);
        return ans;
    }

    int maxValUtil(Node *root)
    {
        if (root == NULL)
            return INT_MIN;
        int ans = root->val;
        ans = max(ans, maxValUtil(root->right));
        return ans;
    }

    int minValUtil(Node *root)
    {
        if (root == NULL)
            return INT_MAX;
        int ans = root->val;
        ans = min(ans, minValUtil(root->left));
        return ans;
    }

    int heightUtil(Node *root)
    {
        if (root == NULL)
            return 0;
        int ans = 1;
        ans = max(ans, heightUtil(root->left) + 1);
        ans = max(ans, heightUtil(root->right) + 1);
        return ans;
    }

    pair<int, int> diameterUtil(Node *root)
    {
        if (root == NULL)
            return {0, 0};
        pair<int, int> lp = diameterUtil(root->left);
        pair<int, int> rp = diameterUtil(root->right);
        int ht = max(lp.first, rp.first) + 1;
        int dia = max(lp.second, max(rp.second, lp.first + rp.first));
        return {ht, dia};
    }
};

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
        cout << front.first->val << " ";
        if (front.first->left)
            q.push(make_pair(front.first->left, front.second + 1));
        if (front.first->right)
            q.push(make_pair(front.first->right, front.second + 1));
    }
    cout << endl;
}

int main()
{
    vector<int> arr1 = {50, 25, 75, 12, 37, 62, 87, -1, -1, 30, -1, -1, 70};
    Node *root1 = takeInput(arr1);
    BST *tree = new BST(root1);
    cout << "SIZE: " << tree->size() << endl;
    cout << "SUM: " << tree->sum() << endl;
    cout << "MAX ELEMENT: " << tree->maxVal() << endl;
    cout << "MIN ELEMENT: " << tree->minVal() << endl;
    cout << "HEIGHT: " << tree->height() << endl;
    cout << "DIAMETER: " << tree->diameter() << endl;
    tree->insert(40);
    cout << "CHECKING FOR 40: " << (tree->search(40) ? "YES" : "NO") << endl;
    tree->insert(60);
    cout << "CHECKING FOR 60: " << (tree->search(60) ? "YES" : "NO") << endl;
    tree->print();
    cout << endl;
    levelorderLinewise(tree->root);
    cout << endl;
    tree->remove(40);
    cout << "CHECKING FOR 40: " << (tree->search(40) ? "YES" : "NO") << endl;
    tree->remove(60);
    cout << "CHECKING FOR 60: " << (tree->search(60) ? "YES" : "NO") << endl;
    tree->print();
    cout << endl;
    levelorderLinewise(tree->root);
    cout << endl;
    delete tree;
    return 0;
}
