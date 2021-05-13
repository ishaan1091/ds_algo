#include <bits/stdc++.h>
using namespace std;

bool checkAnagram(string s, string p, int k)
{
    if (p.length() != s.length())
        return false;
    unordered_map<char, int> map;
    for (auto i : p)
    {
        if (map.count(i))
            map[i]++;
        else
            map[i] = 1;
    }
    for (auto i : s)
    {
        if (map.count(i) && map[i] > 0)
            map[i]--;
    }
    int count = 0;
    unordered_map<char, int>::iterator it = map.begin();
    while (it != map.end())
    {
        count += it->second;
        it++;
    }
    if (count > k)
        return false;
    return true;
}

int main()
{
    string s;
    string p;
    cin >> s >> p;
    int k;
    cin >> k;
    cout << (checkAnagram(s, p, k) ? "true" : "false") << endl;
    return 0;
}