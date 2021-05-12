#include <bits/stdc++.h>
using namespace std;

string minWindow(string s)
{
    unordered_set<char> unique;
    unordered_map<char, int> map;
    for (auto i : s)
    {
        unique.insert(i);
    }
    int i = -1, j = -1;
    string ans = "";
    while (true)
    {
        if (i + 1 < s.length() && map.size() < unique.size())
        {
            i++;
            if (map.count(s[i]) > 0)
            {
                map[s[i]]++;
            }
            else
            {
                map[s[i]] = 1;
            }
        }
        else if (j < i && map.size() == unique.size())
        {
            string potentialAns = s.substr(j + 1, i - j);
            if (potentialAns.length() < ans.length() || ans.length() == 0)
            {
                ans = potentialAns;
            }
            j++;
            map[s[j]]--;
            if (map[s[j]] == 0)
            {
                map.erase(s[j]);
            }
        }
        else
        {
            break;
        }
    }
    return ans;
}

int main()
{
    string ans = minWindow("bbbacabaaccbacabca");
    cout << "SOLUTION: " << ans << endl;
    return 0;
}