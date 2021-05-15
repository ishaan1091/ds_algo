#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> output;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            int front = j + 1;
            int back = nums.size() - 1;
            int target_2 = target - nums[i] - nums[j];
            while (front < back)
            {
                if (nums[front] + nums[back] < target_2)
                    front++;
                else if (nums[front] + nums[back] > target_2)
                    back--;
                else
                {
                    vector<int> quadruplet(4, 0);
                    quadruplet[0] = nums[i];
                    quadruplet[1] = nums[j];
                    quadruplet[2] = nums[front];
                    quadruplet[3] = nums[back];
                    output.push_back(quadruplet);

                    while (front < back && nums[front] == quadruplet[2])
                        front++;
                    while (front < back && nums[back] == quadruplet[3])
                        back--;
                }
            }
            while (j + 1 < nums.size() && nums[j + 1] == nums[j])
                j++;
        }
        while (i + 1 < nums.size() && nums[i + 1] == nums[i])
            i++;
    }
    return output;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int target;
    cin >> target;
    vector<vector<int>> output = fourSum(arr, target);
    for (int i = 0; i < output.size(); i++)
    {
        for (auto j : output[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}