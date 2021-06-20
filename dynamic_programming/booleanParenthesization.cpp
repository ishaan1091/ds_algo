#include <bits/stdc++.h>
using namespace std;

// Recursive Solution
pair<int, int> countWaysHelper(int n, string s)
{
    if (s.length() == 1)
        return (s[0] == 'T' ? make_pair(1, 0) : make_pair(0, 1));
    pair<int, int> ans = make_pair(0, 0);
    for (int i = 0; i < n - 2; i += 2)
    {
        pair<int, int> count1 = countWaysHelper(i + 1, s.substr(0, i + 1));
        pair<int, int> count2 = countWaysHelper(n - i - 2, s.substr(i + 2));
        if (s[i + 1] == '&')
        {
            ans.first += count1.first * count2.first;
            ans.second += count1.first * count2.second + count1.second * count2.first + count1.second * count2.second;
        }
        else if (s[i + 1] == '|')
        {
            ans.first += count1.first * count2.first + count1.first * count2.second + count1.second * count2.first;
            ans.second += count1.second * count2.second;
        }
        else
        {
            ans.first += count1.first * count2.second + count1.second * count2.first;
            ans.second += count1.first * count2.first + count1.second * count2.second;
        }
    }
    return ans;
}

int countWaysRec(int n, string s)
{
    pair<int, int> ans = countWaysHelper(n, s);
    return ans.first;
}

// DP solution
int countWaysDP1(int n, string s)
{
    // code here
    int len = (n + 1) / 2;
    vector<vector<int>> dpt(len, vector<int>(len, 0));
    vector<vector<int>> dpf(len, vector<int>(len, 0));
    for (int g = 0; g < len; g++)
    {
        for (int i = 0, j = i + g; j < len; i++, j++)
        {
            if (g == 0)
            {
                dpt[i][j] = (s[2 * i] == 'T');
                dpf[i][j] = (s[2 * i] == 'F');
            }
            else
            {
                int anst = 0, ansf = 0;
                for (int k = i; k < j; k++)
                {
                    if (s[2 * k + 1] == '&')
                    {
                        anst += dpt[i][k] * dpt[k + 1][j];
                        ansf += dpt[i][k] * dpf[k + 1][j] + dpf[i][k] * dpt[k + 1][j] + dpf[i][k] * dpf[k + 1][j];
                    }
                    else if (s[2 * k + 1] == '|')
                    {
                        anst += dpt[i][k] * dpt[k + 1][j] + dpt[i][k] * dpf[k + 1][j] + dpf[i][k] * dpt[k + 1][j];
                        ansf += dpf[i][k] * dpf[k + 1][j];
                    }
                    else
                    {
                        anst += dpt[i][k] * dpf[k + 1][j] + dpf[i][k] * dpt[k + 1][j];
                        ansf += dpt[i][k] * dpt[k + 1][j] + dpf[i][k] * dpf[k + 1][j];
                    }
                }
                dpt[i][j] = anst;
                dpf[i][j] = ansf;
            }
        }
    }
    return dpt[0][len - 1];
}

int countWaysDP2(int n, string s)
{
    // code here
    vector<vector<int>> dpt(n, vector<int>(n, 0));
    vector<vector<int>> dpf(n, vector<int>(n, 0));
    for (int g = 0; g < n; g += 2)
    {
        for (int i = 0, j = i + g; j < n; i += 2, j += 2)
        {
            if (g / 2 == 0)
            {
                dpt[i][j] = (s[i] == 'T');
                dpf[i][j] = (s[i] == 'F');
            }
            else
            {
                int anst = 0, ansf = 0;
                for (int k = i; k < j; k += 2)
                {
                    if (s[k + 1] == '&')
                    {
                        anst += dpt[i][k] * dpt[k + 2][j];
                        ansf += dpt[i][k] * dpf[k + 2][j] + dpf[i][k] * dpt[k + 2][j] + dpf[i][k] * dpf[k + 2][j];
                    }
                    else if (s[k + 1] == '|')
                    {
                        anst += dpt[i][k] * dpt[k + 2][j] + dpt[i][k] * dpf[k + 2][j] + dpf[i][k] * dpt[k + 2][j];
                        ansf += dpf[i][k] * dpf[k + 2][j];
                    }
                    else
                    {
                        anst += dpt[i][k] * dpf[k + 2][j] + dpf[i][k] * dpt[k + 2][j];
                        ansf += dpt[i][k] * dpt[k + 2][j] + dpf[i][k] * dpf[k + 2][j];
                    }
                }
                dpt[i][j] = anst;
                dpf[i][j] = ansf;
            }
        }
    }
    return dpt[0][n - 1];
}

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = countWaysRec(n, s);
    cout << ans << endl;
    ans = countWaysDP1(n, s);
    cout << ans << endl;
    ans = countWaysDP2(n, s);
    cout << ans << endl;
    return 0;
}