//Recursion
#include <bits/stdc++.h>

int f(int row, int col)
{
    if (row == 0 && col == 0)
        return 1;
    if (row < 0 || col < 0)
        return 0;
    int left = f(row, col - 1);
    int up = f(row - 1, col);
    return left + up;
}

int uniquePaths(int m, int n)
{
    return f(m - 1, n - 1);
}

// memoization
#include <bits/stdc++.h>

int f(int row, int col, vector<vector<int>> &dp)
{
    if (row == 0 && col == 0)
        return 1;
    if (row < 0 || col < 0)
        return 0;
    if (dp[row][col] != -1)
        return dp[row][col];
    int left = f(row, col - 1, dp);
    int up = f(row - 1, col, dp);
    return dp[row][col] = left + up;
}

int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return f(m - 1, n - 1, dp);
}

// Tabulation
#include <bits/stdc++.h>

int f(int row, int col)
{
    vector<vector<int>> dp(row, vector<int>(col, 0));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
                continue;
            }
            int left = 0;
            int up = 0;
            if (i > 0)
                up = dp[i - 1][j];
            if (j > 0)
                left = dp[i][j - 1];
            dp[i][j] = left + up;
        }
    }

    return dp[row - 1][col - 1];
}

int uniquePaths(int m, int n)
{
    return f(m, n);
}
