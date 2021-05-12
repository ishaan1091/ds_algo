#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t)
{
    int matchCount = 0;
    unordered_map<char, int> ms;
    unordered_map<char, int> mt;
    for (auto i : t)
    {
        if (mt.count(i) > 0)
        {
            mt[i]++;
        }
        else
        {
            mt[i] = 1;
        }
    }
    int i = -1, j = -1;
    string ans = "";
    while (true)
    {
        if (i + 1 < s.length() && matchCount < t.length())
        {
            i++;
            if (ms.count(s[i]) > 0)
            {
                ms[s[i]]++;
            }
            else
            {
                ms[s[i]] = 1;
            }
            if (ms[s[i]] <= mt[s[i]])
                matchCount++;
        }
        else if (j < i && matchCount == t.length())
        {
            string potentialAns = s.substr(j + 1, i - j);
            if (potentialAns.length() < ans.length() || ans.length() == 0)
            {
                ans = potentialAns;
            }
            j++;
            ms[s[j]]--;
            if (ms[s[j]] < mt[s[j]])
                matchCount--;
            if (ms[s[j]] == 0)
                ms.erase(s[j]);
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
    string ans = minWindow("bbbacabaaccbacabca", "abc");
    cout << "SOLUTION: " << ans << endl;
    return 0;
}