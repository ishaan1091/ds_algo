#include <bits/stdc++.h>
using namespace std;

bool compare(const vector<int> &arr1, const vector<int> &arr2)
{
    if (arr1[0] == arr2[0])
    {
        return arr1[1] > arr2[1];
    }
    return arr1[0] < arr2[0];
}

int maxEnvelopes(vector<vector<int>> &envelopes)
{
    int n = envelopes.size();
    sort(envelopes.begin(), envelopes.end(), compare);
    vector<int> dp(n, 0);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (count == 0 || dp[count - 1] < envelopes[i][1])
        {
            dp[count++] = envelopes[i][1];
            continue;
        }
        int replaceIndex = lower_bound(dp.begin(), dp.begin() + count, envelopes[i][1]) - dp.begin();
        dp[replaceIndex] = envelopes[i][1];
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> envelopes(n, vector<int>(2, 0));
    for (int i = 0; i < n; i++)
    {
        int width, height;
        cin >> width >> height;
        envelopes[i][0] = width;
        envelopes[i][1] = height;
    }
    int ans = maxEnvelopes(envelopes);
    cout << ans << endl;
    return 0;
}