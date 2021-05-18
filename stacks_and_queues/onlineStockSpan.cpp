#include <bits/stdc++.h>
using namespace std;

class StockSpanner
{
    stack<pair<int, int>> s;

public:
    StockSpanner()
    {
    }

    int next(int price)
    {
        if (!s.size())
        {
            s.push(make_pair(price, 1));
            return 1;
        }
        int count = 0;
        while (s.size() && s.top().first <= price)
        {
            count += s.top().second;
            s.pop();
        }
        s.push(make_pair(price, count + 1));
        return count + 1;
    }
};

int main()
{
    StockSpanner *obj = new StockSpanner();
    cout << obj->next(100) << " ";
    cout << obj->next(80) << " ";
    cout << obj->next(60) << " ";
    cout << obj->next(70) << " ";
    cout << obj->next(60) << " ";
    cout << obj->next(75) << " ";
    cout << obj->next(85) << endl;
    delete obj;
    return 0;
}