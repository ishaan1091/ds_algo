#include <iostream>
#include <vector>
using namespace std;

bool binarySearch(vector<int> arr, int target)
{
    int start = 0, end = arr.size() - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] == target)
        {
            return true;
        }
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return false;
}

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int row = matrix.size() - 1;
    for (int i = 1; i < matrix.size(); i++)
    {
        if (target < matrix[i][0])
        {
            row = i - 1;
            break;
        }
    }
    return binarySearch(matrix[row], target);
}

int main()
{
    vector<vector<int>> matrix;
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        vector<int> temp;
        matrix.push_back(temp);
        for (int j = 0; j < n; j++)
        {
            int element;
            cin >> element;
            matrix[i].push_back(element);
        }
    }
    int target;
    cin >> target;
    bool ans = searchMatrix(matrix, target);
    if (ans == 0)
    {
        cout << "FAlSE" << endl;
    }
    else
    {
        cout << "TRUE" << endl;
    }
    return 0;
}