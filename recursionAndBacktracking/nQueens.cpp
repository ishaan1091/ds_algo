#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, vector<vector<int>> &board)
{
    int n = board.size();
    for (int i = row - 1; i >= 0; i--)
    {
        if (board[i][col] == 1)
        {
            return false;
        }
    }
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    return true;
}

void nQueens(vector<vector<int>> &board, int n, string arrangement = "", int row = 0)
{
    if (row == n)
    {
        cout << arrangement << "." << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (isSafe(row, i, board))
        {
            board[row][i] = 1;
            nQueens(board, n, arrangement + to_string(row) + "-" + to_string(i) + ", ", row + 1);
            board[row][i] = 0;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    nQueens(board, n);
    return 0;
}