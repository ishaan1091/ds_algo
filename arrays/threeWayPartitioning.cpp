#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void threeWayPartition(vector<int> &arr, int a, int b)
{
    int current = 0, zeroPos = 0, twoPos = arr.size() - 1;
    while (current <= twoPos)
    {
        if (arr[current] < a)
        {
            swap(arr[current++], arr[zeroPos++]);
        }
        else if (arr[current] >= a && arr[current] <= b)
        {
            current++;
        }
        else
        {
            swap(arr[current], arr[twoPos--]);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    int a, b;
    cin >> a >> b;
    threeWayPartition(arr, a, b);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}