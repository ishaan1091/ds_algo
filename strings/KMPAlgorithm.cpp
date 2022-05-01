#include <bits/stdc++.h>
using namespace std;

void precompute(string &s, vector<int> &arr)
{
    int i = 1, j = 0, n = s.size();
    while (i < n)
    {
        if (s[i] == s[j])
        {
            arr[i] = j + 1;
            i++, j++;
        }
        else
        {
            if (j == 0)
            {
                arr[i] = 0;
                i++;
            }
            else
            {
                j = arr[j - 1];
            }
        }
    }
}

vector<int> searchPattern(string &text, string &pattern)
{
    int i = 0, j = 0, n = text.size(), m = pattern.size();
    vector<int> output, arr(m, 0);
    precompute(pattern, arr);
    while (i < n)
    {
        if (j >= m)
        {
            output.push_back(i - j);
            j = arr[j - 1];
        }
        else if (text[i] == pattern[j])
        {
            i++, j++;
        }
        else
        {
            if (j > 0)
            {
                j = arr[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
    if (j >= m)
    {
        output.push_back(i - j);
    }
    return output;
}

int main()
{
    string text, pattern;
    cin >> text >> pattern;
    vector<int> ans = searchPattern(text, pattern);
    for (auto i : ans)
        cout << i + 1 << " ";
    cout << endl;
    return 0;
}