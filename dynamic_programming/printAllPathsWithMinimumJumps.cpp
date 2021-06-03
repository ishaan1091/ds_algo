#include <bits/stdc++.h>
using namespace std;

class Pair
{
public:
    string path;
    int i;
};

Pair makePair(int i, string path)
{
    Pair p;
    p.path = path;
    p.i = i;
    return p;
}

void printPaths(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp(n, -1);
    dp[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        int min = INT_MAX;
        for (int j = 1; j <= arr[i] && i + j < n; j++)
        {
            if (dp[i + j] != -1 && min > dp[i + j])
                min = dp[i + j];
        }
        dp[i] = min == INT_MAX ? -1 : min + 1;
    }
    cout << dp[0] << endl;
    queue<Pair> q;
    q.push(makePair(0, "0"));
    while (!q.empty())
    {
        Pair front = q.front();
        q.pop();
        if (front.i == n - 1)
        {
            cout << front.path << " ." << endl;
            continue;
        }
        for (int i = 1; i <= arr[front.i] && i + front.i < n; i++)
        {
            if (dp[i + front.i] == dp[front.i] - 1)
                q.push(makePair(i + front.i, front.path + " -> " + to_string(i + front.i)));
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
    printPaths(arr);
    return 0;
}