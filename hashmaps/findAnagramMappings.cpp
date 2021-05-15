#include <bits/stdc++.h>
using namespace std;

class Pair
{
public:
    int index;
    vector<int> positions;
};

vector<int> findAnagramMappings(vector<int> &s, vector<int> &p)
{
    vector<int> output;
    if (s.size() < p.size())
    {
        return output;
    }
    unordered_map<int, Pair> map;
    for (int i = 0; i < p.size(); i++)
    {
        if (map.count(p[i]))
        {
            map[p[i]].positions.push_back(i);
        }
        else
        {
            Pair temp;
            temp.index = 0;
            map[p[i]] = temp;
            map[p[i]].positions.push_back(i);
        }
    }
    for (int i = 0; i < s.size(); i++)
    {
        output.push_back(map[s[i]].positions[map[s[i]].index++]);
    }
    return output;
}

int main()
{
    int n;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    vector<int> p(n);
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
    }
    vector<int> output = findAnagramMappings(s, p);
    for (auto i : output)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}