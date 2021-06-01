#include <bits/stdc++.h>
using namespace std;

class Pair
{
public:
    int north;
    int south;

    Pair()
    {
    }

    Pair(int north, int south)
    {
        this->north = north;
        this->south = south;
    }
};

bool operator<(const Pair &p1, const Pair &p2)
{
    if (p1.north == p2.north)
        return p1.south < p2.south;
    return p1.north < p2.north;
}

bool operator>(const Pair &p1, const Pair &p2)
{
    if (p1.north == p2.north)
        return p1.south < p2.south;
    return p1.north > p2.north;
}

// O(N^2) solution
int maxBridges1(vector<Pair> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<int> dp(n, 0);
    for (int i = 0; i < n; i++)
    {
        int maxBridge = 0;
        for (int j = 0; j < i; j++)
        {
            if (arr[j].south < arr[i].south)
                maxBridge = max(dp[j], maxBridge);
        }
        dp[i] = maxBridge + 1;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, dp[i]);
    return ans;
}

// O(NlogN) solution
int maxBridges2(vector<Pair> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<int> dp(n, 0);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (count == 0 || dp[count - 1] < arr[i].south)
        {
            dp[count++] = arr[i].south;
            continue;
        }
        int replaceIndex = lower_bound(dp.begin(), dp.begin() + count, arr[i].south) - dp.begin();
        dp[replaceIndex] = arr[i].south;
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    vector<Pair> arr(n);
    for (int i = 0; i < n; i++)
    {
        int north;
        int south;
        cin >> north;
        cin >> south;
        arr[i].north = north;
        arr[i].south = south;
    }
    int ans = maxBridges1(arr);
    cout << "Using Method 1 : " << ans << endl;
    ans = maxBridges2(arr);
    cout << "Using Method 2 : " << ans << endl;
    return 0;
}