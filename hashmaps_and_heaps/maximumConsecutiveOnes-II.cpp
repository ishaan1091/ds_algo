#include <bits/stdc++.h>
using namespace std;

int maxConsecutiveOnes(vector<int> &arr)
{
    int ans = 0;
    int j = -1;
    int count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 0)
        {
            count++;
        }
        while (count > 1)
        {
            j++;
            if (arr[j] == 0)
                count--;
        }
        int len = i - j;
        if (len > ans)
            ans = len;
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1};
    int ans = maxConsecutiveOnes(arr);
    cout << ans << endl;
    return 0;
}