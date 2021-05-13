#include <bits/stdc++.h>
using namespace std;

bool compare(unordered_map<char, int> smap, unordered_map<char, int> pmap)
{
    if (smap.size() != pmap.size())
        return false;
    unordered_map<char, int>::iterator it = pmap.begin();
    while (it != pmap.end())
    {
        if (smap[it->first] != it->second)
            return false;
        it++;
    }
    return true;
}

vector<int> findAnagrams(string s, string p)
{
    vector<int> output;
    unordered_map<char, int> smap;
    unordered_map<char, int> pmap;
    for (auto i : p)
    {
        if (pmap.count(i))
            pmap[i]++;
        else
            pmap[i] = 1;
    }
    int i;
    int j = -1;
    for (i = 0; i < p.length() - 1; i++)
    {
        if (smap.count(s[i]))
            smap[s[i]]++;
        else
            smap[s[i]] = 1;
    }
    while (i < s.length())
    {
        if (smap.count(s[i]))
            smap[s[i]]++;
        else
            smap[s[i]] = 1;
        i++;
        j++;
        if (compare(smap, pmap))
            output.push_back(j);
        smap[s[j]]--;
        if (smap[s[j]] == 0)
            smap.erase(s[j]);
    }
    return output;
}

vector<int> findAnagramsOptimised(string s, string p)
{
    vector<int> output;
    if (s.length() < p.length())
        return output;
    vector<int> smap(128);
    vector<int> pmap(128);
    for (auto i : p)
    {
        pmap[i]++;
    }
    int i;
    int j = -1;
    for (i = 0; i < p.length() - 1; i++)
    {
        smap[s[i]]++;
    }
    while (i < s.length())
    {
        smap[s[i]]++;
        i++;
        j++;
        if (smap == pmap)
            output.push_back(j);
        smap[s[j]]--;
    }
    return output;
}

int main()
{
    string s;
    string p;
    cin >> s >> p;
    vector<int> output = findAnagramsOptimised(s, p);
    cout << output.size() << endl;
    for (auto i : output)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}