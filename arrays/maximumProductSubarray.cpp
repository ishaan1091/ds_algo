#include <iostream>
using namespace std;

// Discuss with jatin as it is wrong
// long long int maxProduct(int arr[], int n)
// {
//     long long int prod = 1, maxProd = arr[0];
//     for (int i = 0; i < n; i++)
//     {
//         prod *= arr[i];
//         cout << arr[i] << " : " << prod << endl;
//         if (prod > maxProd)
//         {
//             maxProd = prod;
//         }
//         if (prod == 0)
//         {
//             prod = 1;
//         }
//     }
//     cout << "maxProd" << maxProd;
//     prod = 1;
//     for (int j = n - 1; j >= 0; j--)
//     {
//         prod *= arr[j];
//         cout << arr[j] << " : " << prod << endl;
//         if (prod > maxProd)
//         {
//             maxProd = prod;
//         }
//         if (prod == 0)
//         {
//             prod = 1;
//         }
//     }
//     cout << "maxProd" << maxProd;
//     return maxProd;
// }

long long maxProduct(int *arr, int n)
{
    long long minVal = arr[0];
    long long maxVal = arr[0];
    long long maxProduct = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < 0)
            swap(maxVal, minVal);
        maxVal = max((long long)arr[i], maxVal * arr[i]);
        minVal = min((long long)arr[i], minVal * arr[i]);
        maxProduct = max(maxProduct, maxVal);
    }
    return maxProduct;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    long long int ans = maxProduct(arr, n);
    cout << ans << endl;
    delete[] arr;
    return 0;
}