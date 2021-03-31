#include <bits/stdc++.h>
using namespace std;

vector<string> getSubsequence(string s)
{
    if (s.length() == 0)
    {
        vector<string> ans;
        ans.push_back("");
        return ans;
    }
    vector<string> ans = getSubsequence(s.substr(1));
    int n = ans.size();
    for (int i = 0; i < n; i++)
    {
        ans.push_back(s[0] + ans[i]);
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    vector<string> v = getSubsequence(s);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    cout << v.size() << endl;
    return 0;
}