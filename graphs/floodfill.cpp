#include <bits/stdc++.h>
using namespace std;

void floodFillUtil(vector<vector<int>> &image, int sr, int sc, int newColor, int color)
{
    if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != color)
    {
        return;
    }

    image[sr][sc] = newColor;
    floodFillUtil(image, sr - 1, sc, newColor, color);
    floodFillUtil(image, sr, sc + 1, newColor, color);
    floodFillUtil(image, sr + 1, sc, newColor, color);
    floodFillUtil(image, sr, sc - 1, newColor, color);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    if (newColor == image[sr][sc])
    {
        return image;
    }
    floodFillUtil(image, sr, sc, newColor, image[sr][sc]);
    return image;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> a(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    int sr, sc, newColor;
    cin >> sr >> sc >> newColor;
    vector<vector<int>> output = floodFill(a, sr, sc, newColor);
    cout << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << output[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}