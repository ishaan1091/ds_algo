#include <bits/stdc++.h>
using namespace std;

long long minCost(long long arr[], long long n)
{
    // Your code here
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }
    long long cost = 0;
    while (pq.size() != 0 && pq.size() != 1)
    {
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();
        cost += a + b;
        pq.push(a + b);
    }
    return cost;
}

int main()
{
    int n;
    cin >> n;
    long long arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << minCost(arr, n) << endl;
    return 0;
}