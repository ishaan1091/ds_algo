#include <bits/stdc++.h>
using namespace std;

void partitionHelper(vector<vector<string>> &output, string &s, int start, vector<string> &path, vector<vector<bool>> &dp)
{
    int n = s.length();
    if (start == n)
    {
        output.push_back(path);
        return;
    }
    for (int i = start; i < n; i++)
    {
        if (dp[start][i])
        {
            path.push_back(s.substr(start, i - start + 1));
            partitionHelper(output, s, i + 1, path, dp);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    int n = s.length();
    vector<vector<bool>> dp(n, vector<bool>(n, 0));
    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = i + g; j < n; i++, j++)
        {
            if (g == 0)
            {
                dp[i][j] = true;
            }
            else if (g == 1)
            {
                dp[i][j] = s[i] == s[j];
            }
            else
            {
                dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
            }
        }
    }
    vector<vector<string>> output;
    vector<string> path;
    partitionHelper(output, s, 0, path, dp);
    return output;
}

int main()
{
    string s;
    cin >> s;
    vector<vector<string>> output = partition(s);
    cout << output.size() << endl;
    for (auto v : output)
    {
        for (auto i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}