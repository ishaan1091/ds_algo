#include <bits/stdc++.h>
using namespace std;

bool isIsomorphic(string s, string t)
{
    if (s.length() != t.length())
        return false;
    unordered_map<char, char> map;
    unordered_map<char, char> mapInverse;
    for (int i = 0; i < s.size(); i++)
    {
        char str = t[i];
        if (map.count(s[i]))
        {
            if (str != map[s[i]])
                return false;
        }
        else
        {
            if (mapInverse.count(str))
                return false;
            map[s[i]] = str;
            mapInverse[str] = s[i];
        }
    }
    return true;
}

int main()
{
    string s, t;
    cin >> s >> t;
    cout << (isIsomorphic(s, t) ? "YES" : "NO") << endl;
    return 0;
}