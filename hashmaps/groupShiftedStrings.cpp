#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupShiftedStrings(vector<string> &strs)
{
    unordered_map<string, vector<string>> map;
    for (int i = 0; i < strs.size(); i++)
    {
        string str = "";
        for (int j = 1; j < strs[i].size(); j++)
        {
            int temp = strs[i][j] - strs[i][j];
            str += to_string(temp) + " ";
        }
        map[str].push_back(strs[i]);
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
    vector<vector<string>> output = groupShiftedStrings(strs);
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