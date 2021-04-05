#include <bits/stdc++.h>
using namespace std;

int countStairPathJumps(int n, vector<int> &jumps)
{
    vector<int> path(n + 1, 0);
    path[n] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 1; j <= jumps[i] && i + j <= n; j++)
        {
            path[i] += path[i + j];
        }
    }
    return path[0];
}

int main()
{
    int n;
    cin >> n;
    vector<int> jumps(n);
    for (int i = 0; i < n; i++)
    {
        cin >> jumps[i];
    }
    int ans = countStairPathJumps(n, jumps);
    cout << ans << endl;
    return 0;
}