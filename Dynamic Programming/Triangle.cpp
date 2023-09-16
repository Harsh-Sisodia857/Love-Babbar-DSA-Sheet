// Recursion
#include <bits/stdc++.h>
int f(vector<vector<int>> &triangle, int n, int i, int j)
{
    if (i == n - 1)
    {
        return triangle[i][j];
    }
    int down = triangle[i][j] + f(triangle, n, i + 1, j);
    int diagonal = triangle[i][j] + f(triangle, n, i + 1, j + 1);
    return min(down, diagonal);
}
int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    // starting from fixed postion that is 0th index
    return f(triangle, n, 0, 0);
}

// memoization
#include <bits/stdc++.h>
int f(vector<vector<int>> &triangle, int n, int i, int j, vector<vector<int>> &dp)
{
    if (i == n - 1)
    {
        return triangle[i][j];
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    int down = triangle[i][j] + f(triangle, n, i + 1, j, dp);
    int diagonal = triangle[i][j] + f(triangle, n, i + 1, j + 1, dp);
    return dp[i][j] = min(down, diagonal);
}
int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, -1));
    // starting from fixed postion that is 0th index
    return f(triangle, n, 0, 0, dp);
}

// iterative
#include <bits/stdc++.h>
int f(vector<vector<int>> &triangle, int n, vector<vector<int>> &dp)
{
    for (int row = n - 1; row >= 0; row--)
    {
        for (int col = row; col >= 0; col--)
        {
            if (row == n - 1)
            {
                dp[n - 1][col] = triangle[n - 1][col];
                continue;
            }
            int up = triangle[row][col] + dp[row + 1][col];
            int diagonal = triangle[row][col] + dp[row + 1][col + 1];
            dp[row][col] = min(up, diagonal);
        }
    }
    return dp[0][0];
}

int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    vector<vector<int>> dp(n, vector<int>(n, 0));
    // starting from fixed postion that is 0th index
    return f(triangle, n, dp);
}