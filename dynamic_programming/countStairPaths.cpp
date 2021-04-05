#include <bits/stdc++.h>
using namespace std;

int countStairPathsMemoization(int n, vector<int> &paths)
{
    if (n == 0)
    {
        paths[0] = 0;
        return 1;
    }
    else if (n < 0)
    {
        return 0;
    }
    if (paths[n] != -1)
    {
        return paths[n];
    }
    paths[n] = countStairPathsMemoization(n - 1, paths) + countStairPathsMemoization(n - 2, paths) + countStairPathsMemoization(n - 3, paths);
    return paths[n];
}

int countStairPathsTabulation(int n)
{
    vector<int> paths(n + 1);
    paths[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            paths[i] = paths[i - 1];
        }
        else if (i == 2)
        {
            paths[i] = paths[i - 1] + paths[i - 2];
        }
        else
        {
            paths[i] = paths[i - 1] + paths[i - 2] + paths[i - 3];
        }
    }
    return paths[n];
}

int main()
{
    int n;
    cin >> n;
    vector<int> paths(n + 1, -1);
    int ans = countStairPathsMemoization(n, paths);
    cout << "Solution by Memoization: " << ans << endl;
    ans = countStairPathsTabulation(n);
    cout << "Solution by Tabulation: " << ans << endl;
    return 0;
}