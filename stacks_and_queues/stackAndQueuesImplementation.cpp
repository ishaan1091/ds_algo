#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Stack
{
private:
    T *arr;
    int currSize, capacity;

public:
    Stack()
    {
        arr = new T[5], currSize = 0, capacity = 5;
    }

    ~Stack()
    {
        delete[] arr;
    }

    int size()
    {
        return currSize;
    }

    bool empty()
    {
        return currSize == 0;
    }

    void push(T val)
    {
        if (currSize == capacity)
        {
            T *newArr = new T[2 * capacity];
            capacity *= 2;
            for (int i = 0; i < currSize; i++)
                newArr[i] = arr[i];
            delete[] arr;
            arr = newArr;
        }
        arr[currSize++] = val;
    }

    void pop()
    {
        if (this->empty())
            return;
        currSize--;
    }

    T top()
    {
        if (this->empty())
            return INT_MIN;
        return arr[currSize - 1];
    }
};

template <typename T>
class Queue
{
private:
    T *arr;
    int currSize, start, end, capacity;

public:
    Queue()
    {
        arr = new T[5], start = 0, end = -1, capacity = 5, currSize = 0;
    }

    ~Queue()
    {
        delete[] arr;
    }

    int size()
    {
        return currSize;
    }

    bool empty()
    {
        return currSize == 0;
    }

    void push(T val)
    {
        if (currSize == capacity)
        {
            T *newArr = new T[2 * capacity];
            capacity *= 2;
            for (int i = start; i != end; i = (i + 1) % currSize)
                newArr[(i - start + currSize) % currSize] = arr[i];
            start = 0, end = currSize - 1;
            delete[] arr;
            arr = newArr;
        }
        end = (end + 1) % capacity;
        arr[end] = val;
        currSize++;
    }

    void pop()
    {
        if (this->empty())
            return;
        currSize--, start = (start + 1) % capacity;
    }

    T front()
    {
        if (this->empty())
            return INT_MIN;
        return arr[start];
    }
};

template <typename T>
class Node
{
public:
    T val;
    Node<T> *next;

    Node(T val)
    {
        this->val = val;
        next = NULL;
    }

    ~Node()
    {
        delete next;
    }
};

template <typename T>
class StackUsingLL
{
private:
    Node<T> *head;
    int currSize;

public:
    StackUsingLL()
    {
        head = NULL;
        currSize = 0;
    }

    ~StackUsingLL()
    {
        delete head;
    }

    int size()
    {
        return currSize;
    }

    bool empty()
    {
        return currSize == 0;
    }

    void push(T val)
    {
        Node<T> *newNode = new Node<T>(val);
        newNode->next = head;
        head = newNode;
        currSize++;
    }

    void pop()
    {
        if (this->empty())
            return;
        currSize--;
        Node<T> *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    T top()
    {
        if (this->empty())
            return INT_MIN;
        return head->val;
    }
};

template <typename T>
class QueueUsingLL
{
private:
    Node<T> *head, *tail;
    int currSize;

public:
    QueueUsingLL()
    {
        head = tail = NULL;
        currSize = 0;
    }

    ~QueueUsingLL()
    {
        delete head;
    }

    int size()
    {
        return currSize;
    }

    bool empty()
    {
        return currSize == 0;
    }

    void push(T val)
    {
        Node<T> *newNode = new Node<T>(val);
        currSize++;
        if (tail)
            tail->next = newNode;
        else
            head = newNode;
        tail = newNode;
    }

    void pop()
    {
        if (this->empty())
            return;
        currSize--;
        Node<T> *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        if (head == NULL)
            tail = NULL;
    }

    T front()
    {
        if (this->empty())
            return INT_MIN;
        return head->val;
    }
};

int main()
{
    // Stack<int> s;
    // Queue<int> q;
    // StackUsingLL<int> s;
    QueueUsingLL<int> q;
    cout << q.size() << endl;
    cout << (q.empty() ? "YES" : "NO") << endl;
    cout << q.front() << endl;
    q.push(5);
    q.push(4);
    cout << q.size() << endl;
    cout << (q.empty() ? "YES" : "NO") << endl;
    cout << q.front() << endl;
    q.pop();
    cout << q.size() << endl;
    cout << (q.empty() ? "YES" : "NO") << endl;
    cout << q.front() << endl;
    q.push(6);
    q.push(8);
    q.push(9);
    cout << q.size() << endl;
    cout << (q.empty() ? "YES" : "NO") << endl;
    cout << q.front() << endl;
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    cout << q.size() << endl;
    cout << (q.empty() ? "YES" : "NO") << endl;
    cout << q.front() << endl;
    return 0;
}