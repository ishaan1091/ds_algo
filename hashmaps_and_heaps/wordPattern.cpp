#include <bits/stdc++.h>
using namespace std;

bool wordPattern(string pattern, string s)
{
    unordered_map<char, string> map;
    unordered_map<string, char> mapInverse;
    int j = 0;
    for (int i = 0; i < pattern.size(); i++)
    {
        string str = "";
        while (s[j] != ' ' && s[j] != '\0')
        {
            str += s[j];
            j++;
        }
        j++;
        if (map.count(pattern[i]))
        {
            if (str != map[pattern[i]])
                return false;
        }
        else
        {
            if (mapInverse.count(str))
                return false;
            map[pattern[i]] = str;
            mapInverse[str] = pattern[i];
        }
    }
    if (j != s.length() + 1)
        return false;
    return true;
}

int main()
{
    char s[3000];
    cin.getline(s, 3000);
    string str;
    int i = 0;
    while (s[i] != '\0')
    {
        str += s[i];
        i++;
    }
    string pattern;
    cin >> pattern;
    cout << (wordPattern(pattern, str) ? "YES" : "NO") << endl;
    return 0;
}