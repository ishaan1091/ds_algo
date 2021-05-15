#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    int ans = 0;
    int i = -1, j = -1;
    unordered_map<char, int> map;
    while (true)
    {
        bool f1 = true, f2 = true;
        while (i + 1 < (int)s.length())
        {
            i++;
            f1 = false;
            if (map.count(s[i]))
            {
                map[s[i]]++;
                break;
            }
            else
            {
                map[s[i]] = 1;
                ans += i - j;
            }
        }
        while (j < i)
        {
            j++;
            map[s[j]]--;
            f2 = false;
            if (map[s[j]] == 1)
            {
                ans += i - j;
                break;
            }
            if (map[s[j]] == 0)
                map.erase(s[j]);
        }
        if (f1 && f2)
            break;
    }
    return ans;
}

int main()
{
    int ans = lengthOfLongestSubstring("aabcbcdbca");
    cout << "SOLUTION: " << ans << endl;
    return 0;
}