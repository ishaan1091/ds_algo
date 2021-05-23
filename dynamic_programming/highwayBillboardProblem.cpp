#include <bits/stdc++.h>
using namespace std;

// O(n^2) approach
int maxRevenue1(int m, vector<int> &boards, vector<int> &revenue, int gap)
{
    int n = boards.size();
    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++)
    {
        int maxRevenue = 0;
        for (int j = 0; j < i; j++)
        {
            if (boards[i] - boards[j] > gap)
                maxRevenue = max(maxRevenue, dp[j]);
        }
        dp[i] = maxRevenue + revenue[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, dp[i]);
    }
    return ans;
}

// O(m) approach
int maxRevenue2(int m, vector<int> &boards, vector<int> &revenue, int gap)
{
    vector<int> dp(m, 0);
    int j = 0;
    for (int i = 0; i < m; i++)
    {
        if (boards[j] == i)
        {
            dp[i] = max((i == 0 ? 0 : dp[i - 1]), (i > gap ? dp[i - gap - 1] + revenue[j] : 0));
            j++;
        }
        else
        {
            dp[i] = i == 0 ? 0 : dp[i - 1];
        }
    }
    return dp[m - 1];
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<int> boards(n);
    for (int i = 0; i < n; i++)
        cin >> boards[i];
    vector<int> revenue(n);
    for (int i = 0; i < n; i++)
        cin >> revenue[i];
    int gap;
    cin >> gap;
    int ans = maxRevenue1(m, boards, revenue, gap);
    cout << ans << endl;
    ans = maxRevenue2(m, boards, revenue, gap);
    cout << ans << endl;
    return 0;
}