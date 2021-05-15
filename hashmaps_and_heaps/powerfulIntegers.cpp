#include <bits/stdc++.h>
using namespace std;

vector<int> powerfulIntegers(int x, int y, int bound)
{
    vector<int> xpowers;
    vector<int> ypowers;
    int prod = 1;
    while (prod <= bound)
    {
        xpowers.push_back(prod);
        prod *= x;
        if (x == 1)
            break;
    }
    prod = 1;
    while (prod <= bound)
    {
        ypowers.push_back(prod);
        prod *= y;
        if (y == 1)
            break;
    }
    unordered_set<int> output;
    for (int i = 0; i < xpowers.size(); i++)
    {
        for (int j = 0; j < ypowers.size(); j++)
        {
            if (xpowers[i] + ypowers[j] <= bound)
                output.insert(xpowers[i] + ypowers[j]);
        }
    }
    vector<int> res;
    for (auto i : output)
    {
        res.push_back(i);
    }
    return res;
}

int main()
{
    int x, y, bound;
    cin >> x >> y >> bound;
    vector<int> output = powerfulIntegers(x, y, bound);
    for (auto i : output)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}