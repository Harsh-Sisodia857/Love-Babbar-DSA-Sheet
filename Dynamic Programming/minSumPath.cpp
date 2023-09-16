#include <bits/stdc++.h>
using namespace std;
// recursion
int f(vector<vector<int>> &grid, int r, int c)
{
    if (r < 0 || c < 0)
    {
        return 1e9;
    }
    if (r == 0 && c == 0)
    {
        return grid[r][c];
    }

    int up = grid[r][c] + f(grid, r - 1, c);
    int left = grid[r][c] + f(grid, r, c - 1);
    return min(left, up);
}

int minSumPath(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    return f(grid, n - 1, m - 1);
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> grid = {
        {6, 9, 3},
        {5, 20, 7},
        {9, 13, 10}};
    cout << minSumPath(grid);
    return 0;
}

// memoization
#include <bits/stdc++.h>

int f(vector<vector<int>> &grid, int r, int c, vector<vector<int>> &dp)
{
    if (r < 0 || c < 0)
    {
        return 1e9;
    }
    if (r == 0 && c == 0)
    {
        return grid[r][c];
    }
    if (dp[r][c] != -1)
        return dp[r][c];

    int up = grid[r][c] + f(grid, r - 1, c, dp);
    int left = grid[r][c] + f(grid, r, c - 1, dp);
    return dp[r][c] = min(left, up);
}

int minSumPath(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f(grid, n - 1, m - 1, dp);
}

// iterative
#include <bits/stdc++.h>

int f(vector<vector<int>> &grid, int r, int c)
{

    vector<vector<int>> dp(r, vector<int>(c, -1));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = grid[i][j];
                continue;
            }
            int up = grid[i][j];
            if (i > 0)
                up += dp[i - 1][j];
            else
                up += 1e9;
            int left = grid[i][j];
            if (j > 0)
                left += dp[i][j - 1];
            else
                left += 1e9;
            dp[i][j] = min(left, up);
        }
    }
    return dp[r - 1][c - 1];
}

int minSumPath(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    return f(grid, n, m);
}
