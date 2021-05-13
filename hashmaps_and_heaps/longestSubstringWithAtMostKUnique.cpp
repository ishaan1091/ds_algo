#include <bits/stdc++.h>
using namespace std;

int longestSubstringWithAtMostKUnique(string s, int k)
{
    int ans = 0;
    int j = -1;
    unordered_map<char, int> map;
    for (int i = 0; i < s.length(); i++)
    {
        if (map.count(s[i]))
        {
            map[s[i]]++;
        }
        else
        {
            map[s[i]] = 1;
        }
        if (map.size() <= k)
        {
            if (i - j > ans)
                ans = i - j;
        }
        while (map.size() > k && j < i)
        {
            j++;
            map[s[j]]--;
            if (map[s[j]] == 0)
            {
                map.erase(s[j]);
            }
            if (map.size() == k)
            {
                if (i - j > ans)
                    ans = i - j;
            }
        }
    }
    return ans;
}

int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    int ans = longestSubstringWithAtMostKUnique(s, k);
    cout << ans << endl;
    return 0;
}