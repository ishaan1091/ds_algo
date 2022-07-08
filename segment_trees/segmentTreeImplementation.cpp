#include <bits/stdc++.h>
using namespace std;

// Normal Segment Tree
class SegTree
{
public:
    int n;
    vector<int> seg;

    SegTree(vector<int> &arr)
    {
        n = arr.size();
        seg.resize(4 * n + 1);
        this->build(arr, 0, n - 1, 0);
    }

    void build(vector<int> &arr, int start, int end, int idx)
    {
        if (start == end)
        {
            seg[idx] = arr[start];
            return;
        }
        int mid = start + (end - start) / 2;
        build(arr, start, mid, 2 * idx + 1);
        build(arr, mid + 1, end, 2 * idx + 2);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    int query(int l, int r)
    {
        return this->query(0, n - 1, l, r, 0);
    }

    int query(int start, int end, int l, int r, int idx)
    {
        if (end < l || start > r)
            return 0;
        if (start >= l && end <= r)
            return seg[idx];
        int mid = start + (end - start) / 2;
        int left = query(start, mid, l, r, 2 * idx + 1);
        int right = query(mid + 1, end, l, r, 2 * idx + 2);
        return left + right;
    }

    void pointUpdate(int node, int val)
    {
        this->pointUpdate(0, n - 1, node, val, 0);
    }

    void pointUpdate(int start, int end, int node, int val, int idx)
    {
        if (start == end)
        {
            seg[idx] += val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (node <= mid)
            pointUpdate(start, mid, node, val, 2 * idx + 1);
        else
            pointUpdate(mid + 1, end, node, val, 2 * idx + 2);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }
};

// Segment Tree With Lazy Propagation
class SegTreeLazy
{
public:
    int n;
    vector<int> seg;
    vector<int> updates;

    SegTreeLazy(vector<int> &arr)
    {
        n = arr.size();
        seg.resize(4 * n + 1);
        updates.resize(4 * n + 1);
        this->build(arr, 0, n - 1, 0);
    }

    void build(vector<int> &arr, int start, int end, int idx)
    {
        if (start == end)
        {
            seg[idx] = arr[start];
            return;
        }
        int mid = start + (end - start) / 2;
        build(arr, start, mid, 2 * idx + 1);
        build(arr, mid + 1, end, 2 * idx + 2);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    void checkUpdate(int start, int end, int idx)
    {
        int cnt = end - start + 1;
        seg[idx] += updates[idx] * cnt;
        if (start != end)
        {
            updates[2 * idx + 1] += updates[idx];
            updates[2 * idx + 2] += updates[idx];
        }
        updates[idx] = 0;
    }

    int query(int l, int r)
    {
        return query(0, n - 1, l, r, 0);
    }

    int query(int start, int end, int l, int r, int idx)
    {
        checkUpdate(start, end, idx);
        if (end < l || start > r)
            return 0;
        if (start >= l && end <= r)
            return seg[idx];
        int mid = start + (end - start) / 2;
        int left = query(start, mid, l, r, 2 * idx + 1);
        int right = query(mid + 1, end, l, r, 2 * idx + 2);
        return left + right;
    }

    void pointUpdate(int node, int val)
    {
        lazyUpdate(0, n - 1, node, node, val, 0);
    }

    void rangeUpdate(int l, int r, int val)
    {
        lazyUpdate(0, n - 1, l, r, val, 0);
    }

    void lazyUpdate(int start, int end, int l, int r, int val, int idx)
    {
        checkUpdate(start, end, idx);
        if (start >= l && end <= r)
        {
            updates[idx] += val;
            checkUpdate(start, end, idx);
            return;
        }
        if (end < l || start > r)
            return;
        int mid = start + (end - start) / 2;
        lazyUpdate(start, mid, l, r, val, 2 * idx + 1);
        lazyUpdate(mid + 1, end, l, r, val, 2 * idx + 2);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }
};

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    SegTreeLazy st(arr);
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int a, b, x;
            cin >> a >> b >> x;
            st.rangeUpdate(a - 1, b - 1, x);
        }
        else if (type == 2)
        {
            int a, x;
            cin >> a >> x;
            st.pointUpdate(a - 1, x);
        }
        else
        {
            int a, b;
            cin >> a >> b;
            cout << st.query(a - 1, b - 1) << endl;
        }
    }
    return 0;
}