#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> map;
    for (int i = 0; i < strs.size(); i++)
    {
        string s = strs[i];
        sort(s.begin(), s.end());
        map[s].push_back(strs[i]);
    }
    unordered_map<string, vector<string>>::iterator it = map.begin();
    vector<vector<string>> output;
    while (it != map.end())
    {
        output.push_back(it->second);
        it++;
    }
    return output;
}

int main()
{
    int n;
    cin >> n;
    vector<string> strs(n);
    for (int i = 0; i < n; i++)
    {
        cin >> strs[i];
    }
    vector<vector<string>> output = groupAnagrams(strs);
    for (int i = 0; i < output.size(); i++)
    {
        for (auto i : output[i])
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}