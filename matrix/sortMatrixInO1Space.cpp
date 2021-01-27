#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void sortMatrix(int arr[][100], int m, int n)
{
    for (int i = 0; i < n * m; i++)
    {
        for (int j = 0; j < n * m - 1; j++)
        {
            if (arr[j / n][j % n] > arr[(j + 1) / n][(j + 1) % n])
            {
                swap(arr[j / n][j % n], arr[(j + 1) / n][(j + 1) % n]);
            }
        }
    }
}

int main()
{
    int arr[100][100];
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    sortMatrix(arr, m, n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}