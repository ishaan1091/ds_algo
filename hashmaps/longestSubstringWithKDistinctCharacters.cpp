#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s, int k)
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
            }
            else
            {
                map[s[i]] = 1;
            }
            if (map.size() == k)
            {
                string potentialAns = s.substr(j + 1, i - j);
                if (potentialAns.length() > ans)
                    ans = potentialAns.length();
            }
            else if (map.size() > k)
            {
                break;
            }
        }
        while (j < i)
        {
            j++;
            map[s[j]]--;
            f2 = false;
            if (map[s[j]] == 0)
                map.erase(s[j]);
            if (map.size() == k)
            {
                string potentialAns = s.substr(j + 1, i - j);
                if (potentialAns.length() > ans)
                    ans = potentialAns.length();
                break;
            }
        }
        if (f1 && f2)
            break;
    }
    return ans;
}

int main()
{
    int ans = lengthOfLongestSubstring("aabcbcdbca", 2);
    cout << "SOLUTION: " << ans << endl;
    return 0;
}