#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isSafe(int col, int row, vector<string> &board, int n)
    {
        int dupRow = row;
        int dupCol = col;
        // 1st cond
        while (dupRow >= 0 && dupCol >= 0)
        {
            if (board[dupRow][dupCol] == 'Q')
                return false;
            dupRow--;
            dupCol--;
        }
        // 2nd cond
        dupCol = col;
        while (dupCol >= 0)
        {
            if (board[row][dupCol] == 'Q')
                return false;
            dupCol--;
        }
        // 3rd cond
        dupCol = col;
        dupRow = row;
        while (dupCol >= 0 && dupRow < n)
        {
            if (board[dupRow][dupCol] == 'Q')
                return false;
            dupCol--;
            dupRow++;
        }
        return true;
    }
    void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++)
        {
            if (isSafe(col, row, board, n))
            {
                board[row][col] = 'Q';
                solve(col + 1, board, ans, n);
                board[row][col] = '.';
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
            board[i] = s;
        int col = 0;
        solve(0, board, ans, n);
        return ans;
    }
};