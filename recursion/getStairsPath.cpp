#include <bits/stdc++.h>
using namespace std;

vector<string> getStairsPath(int n)
{
    if (n < 0)
    {
        vector<string> ans;
        return ans;
    }
    if (n == 0)
    {
        vector<string> ans;
        ans.push_back("");
        return ans;
    }
    vector<string> ans;
    for (int i = 1; i <= n && i <= 3; i++)
    {
        vector<string> output = getStairsPath(n - i);
        char c = i + 48;
        for (int j = 0; j < output.size(); j++)
        {
            ans.push_back(c + output[j]);
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<string> v = getStairsPath(n);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    cout << v.size() << endl;
    return 0;
}