#include <bits/stdc++.h>
using namespace std;

int findKthSmallest(vector<int> &nums, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(nums[i]);
    }
    for (int i = k; i < nums.size(); i++)
    {
        if (nums[i] < pq.top())
        {
            pq.pop();
            pq.push(nums[i]);
        }
    }
    return pq.top();
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int k;
    cin >> k;
    int ans = findKthSmallest(nums, k);
    cout << ans << endl;
    return 0;
}