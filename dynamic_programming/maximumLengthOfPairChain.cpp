#include <bits/stdc++.h>
using namespace std;

// Greedy solution
bool comp(vector<int> &p1, vector<int> &p2)
{
    return (p1[1] < p2[1]);
}

int findLongestChainGreedy(vector<vector<int>> &pairs)
{
    sort(pairs.begin(), pairs.end(), comp);
    int curr = INT_MIN, ans = 0;
    for (auto pair : pairs)
    {
        if (pair[0] > curr)
        {
            ans++;
            curr = pair[1];
        }
    }
    return ans;
}

// DP solution
int findLongestChainDP(vector<vector<int>> &pairs)
{
    sort(pairs.begin(), pairs.end());
    int n = pairs.size();
    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++)
    {
        int maxLen = 0;
        for (int j = i; j >= 0; j--)
        {
            if (pairs[j][1] < pairs[i][0])
            {
                maxLen = max(maxLen, dp[j]);
            }
        }
        dp[i] = maxLen + 1;
    }
    return dp[n - 1];
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> pairs(n, vector<int>(2));
    for (int i = 0; i < n; i++)
        cin >> pairs[i][0] >> pairs[i][1];
    int ans = findLongestChainGreedy(pairs);
    cout << ans << endl;
    int ans = findLongestChainDP(pairs);
    cout << ans << endl;
    return 0;
}