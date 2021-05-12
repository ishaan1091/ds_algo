#include <bits/stdc++.h>
using namespace std;

void removeFromMap(unordered_map<char, int> &map, char key)
{
    if (!map.count(key))
        return;
    map[key]--;
    if (map[key] == 0)
        map.erase(key);
}

int solutionForK1(string s)
{
    int ans = 0;
    unordered_map<char, int> map;
    int i = -1, j = -1;
    while (true)
    {
        bool f1 = false, f2 = false;
        while (i + 1 < s.length())
        {
            i++;
            f1 = true;
            if (map.count(s[i]))
            {
                map[s[i]]++;
            }
            else
            {
                map[s[i]] = 1;
            }
            if (map.size() == 2)
            {
                removeFromMap(map, s[i]);
                i--;
                break;
            }
        }
        while (j < i)
        {
            if (map.size() == 1)
            {
                ans += i - j;
            }
            j++;
            f2 = true;
            removeFromMap(map, s[j]);
            if (map.size() == 0)
            {
                break;
            }
        }
        if (!f1 && !f2)
            break;
    }
    return ans;
}

int countSubstrings(string s, int k)
{
    int ans = 0;
    unordered_map<char, int> mapBig;
    unordered_map<char, int> mapSmall;
    int iBig = -1, iSmall = -1, j = -1;
    if (k == 1)
    {
        return solutionForK1(s);
    }
    while (true)
    {
        bool f1 = false, f2 = false, f3 = false;
        while (iBig + 1 < s.length())
        {
            iBig++;
            f1 = true;
            if (mapBig.count(s[iBig]))
            {
                mapBig[s[iBig]]++;
            }
            else
            {
                mapBig[s[iBig]] = 1;
            }
            if (mapBig.size() == k + 1)
            {
                removeFromMap(mapBig, s[iBig]);
                iBig--;
                break;
            }
        }
        while (iSmall < iBig)
        {
            iSmall++;
            f2 = true;
            if (mapSmall.count(s[iSmall]))
            {
                mapSmall[s[iSmall]]++;
            }
            else
            {
                mapSmall[s[iSmall]] = 1;
            }
            if (mapSmall.size() == k)
            {
                removeFromMap(mapSmall, s[iSmall]);
                iSmall--;
                break;
            }
        }
        while (j < iSmall)
        {
            if (mapBig.size() == k && mapSmall.size() == k - 1)
            {
                ans += iBig - iSmall;
            }
            j++;
            f3 = true;
            removeFromMap(mapBig, s[j]);
            removeFromMap(mapSmall, s[j]);
            if (mapBig.size() < k || mapSmall.size() < k - 1)
            {
                break;
            }
        }
        if (!f1 && !f2 && !f3)
        {
            break;
        }
    }
    return ans;
}

int main()
{
    int ans = countSubstrings("aaab", 1);
    cout << "SOLUTION: " << ans << endl;
    return 0;
}