#include <bits/stdc++.h>
using namespace std;

vector<string> getMazePaths(int sr, int sc, int er, int ec)
{
    if (er == sr && ec == sc)
    {
        vector<string> ans;
        ans.push_back("");
        return ans;
    }
    vector<string> top, left;
    if (er - 1 >= sr)
    {
        top = getMazePaths(sr, sc, er - 1, ec);
    }
    if (ec - 1 >= sc)
    {
        left = getMazePaths(sr, sc, er, ec - 1);
    }
    vector<string> ans;
    for (int i = 0; i < top.size(); i++)
    {
        ans.push_back(top[i] + "v");
    }
    for (int i = 0; i < left.size(); i++)
    {
        ans.push_back(left[i] + "h");
    }
    return ans;
}

int main()
{
    int sr, sc, er, ec;
    cin >> sr >> sc >> er >> ec;
    vector<string> v = getMazePaths(sr, sc, er, ec);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    cout << v.size() << endl;
    return 0;
}