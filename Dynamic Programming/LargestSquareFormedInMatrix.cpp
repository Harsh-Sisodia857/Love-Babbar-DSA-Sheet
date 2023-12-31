// recursion
int solve(int row, int col, int n, int m, vector<vector<int>> mat, int &maxi)
{
    if (row >= n || col >= m)
        return 0;
    int right = solve(row, col + 1, n, m, mat, maxi);
    int down = solve(row + 1, col, n, m, mat, maxi);
    int diagonal = solve(row + 1, col + 1, n, m, mat, maxi);
    if (mat[row][col] == 1)
    {
        int ans = 1 + min({right, down, diagonal});
        maxi = max(maxi, ans);
        return ans;
    }
    else
    {
        return 0;
    }
}
int maxSquare(int n, int m, vector<vector<int>> mat)
{
    int maxi = 0;
    solve(0, 0, n, m, mat, maxi);
    return maxi;
}

// memoization
int solve(int row, int col, int n, int m, vector<vector<int>> &mat,
          int &maxi, vector<vector<int>> &dp)
{
    if (row >= n || col >= m)
        return 0;
    if (dp[row][col] != -1)
        return dp[row][col];
    int right = solve(row, col + 1, n, m, mat, maxi, dp);
    int down = solve(row + 1, col, n, m, mat, maxi, dp);
    int diagonal = solve(row + 1, col + 1, n, m, mat, maxi, dp);
    if (mat[row][col] == 1)
    {
        int ans = 1 + min({right, down, diagonal});
        maxi = max(maxi, ans);
        return dp[row][col] = ans;
    }
    else
    {
        return dp[row][col] = 0;
    }
}

// Tabulation
int solveTab(int n, int m, vector<vector<int>> &mat,
             int &maxi, vector<vector<int>> &dp)
{

    for (int row = n - 1; row >= 0; row--)
    {
        for (int col = m - 1; col >= 0; col--)
        {
            int right = dp[row][col + 1];
            int down = dp[row + 1][col];
            int diagonal = dp[row + 1][col + 1];
            if (mat[row][col] == 1)
            {
                int ans = 1 + min({right, down, diagonal});
                maxi = max(maxi, ans);
                dp[row][col] = ans;
            }
            else
            {
                dp[row][col] = 0;
            }
        }
    }
    return dp[0][0];
}

int maxSquare(int n, int m, vector<vector<int>> mat)
{
    int maxi = 0;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    solveTab(n, m, mat, maxi, dp);
    return maxi;
}