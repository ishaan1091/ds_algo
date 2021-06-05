#include <bits/stdc++.h>
using namespace std;

class Pair
{
public:
    string seq;
    int i;
    int len;
};

Pair makePair(string seq, int i, int len)
{
    Pair p;
    p.seq = seq;
    p.i = i;
    p.len = len;
    return p;
}

void printLIS(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n);
    for (int i = 0; i < n; i++)
    {
        int maxLen = 0;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
                maxLen = max(maxLen, dp[j]);
        }
        dp[i] = maxLen + 1;
    }
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (dp[i] > dp[ans])
            ans = i;
    }
    cout << dp[ans] << endl;
    queue<Pair> q;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == dp[ans])
            q.push(makePair(to_string(arr[i]), i, dp[i]));
    }
    while (!q.empty())
    {
        Pair front = q.front();
        q.pop();
        if (front.len == 1)
        {
            cout << front.seq << endl;
            continue;
        }
        for (int i = front.i - 1; i >= 0; i--)
        {
            if (arr[i] < arr[front.i] && dp[i] == front.len - 1)
                q.push(makePair(to_string(arr[i]) + " -> " + front.seq, i, front.len - 1));
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    printLIS(arr);
    return 0;
}