#include <bits/stdc++.h>
using namespace std;

vector<string> getMazePathsWithJumps(int sr, int sc, int er, int ec)
{
    if (sr == er && sc == ec)
    {
        vector<string> ans;
        ans.push_back("");
        return ans;
    }
    vector<string> temp;
    vector<string> ans;
    for (int i = 1; er - i >= sr && ec - i >= sc; i++)
    {
        temp = getMazePathsWithJumps(sr, sc, er - i, ec - i);
        for (int j = 0; j < temp.size(); j++)
        {
            ans.push_back((temp[j] + "d" + to_string(i)));
        }
    }
    for (int i = 1; er - i >= sr; i++)
    {
        temp = getMazePathsWithJumps(sr, sc, er - i, ec);
        for (int j = 0; j < temp.size(); j++)
        {
            ans.push_back(temp[j] + "v" + to_string(i));
        }
    }
    for (int i = 1; ec - i >= sc; i++)
    {
        temp = getMazePathsWithJumps(sr, sc, er, ec - i);
        for (int j = 0; j < temp.size(); j++)
        {
            ans.push_back(temp[j] + "h" + to_string(i));
        }
    }
    return ans;
}

int main()
{
    int sr, sc, er, ec;
    cin >> sr >> sc >> er >> ec;
    vector<string> v = getMazePathsWithJumps(sr, sc, er, ec);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    cout << v.size() << endl;
    return 0;
}