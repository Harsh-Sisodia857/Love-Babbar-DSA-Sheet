#include <bits/stdc++.h>

using namespace std;
// memoization
int getMaxUtil(int i, int j, int m, vector<vector<int>> &matrix,
               vector<vector<int>> &dp)
{

    // Base Conditions
    if (j < 0 || j >= m)
        return -1e9;
    if (i == 0)
        return matrix[0][j];

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = matrix[i][j] + getMaxUtil(i - 1, j, m, matrix, dp);
    int leftDiagonal = matrix[i][j] + getMaxUtil(i - 1, j - 1, m, matrix, dp);
    int rightDiagonal = matrix[i][j] + getMaxUtil(i - 1, j + 1, m, matrix, dp);

    return dp[i][j] = max(up, max(leftDiagonal, rightDiagonal));
}

int getMaxPathSum(vector<vector<int>> &matrix)
{

    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    int maxi = INT_MIN;

    for (int j = 0; j < m; j++)
    {
        int ans = getMaxUtil(n - 1, j, m, matrix, dp);
        maxi = max(maxi, ans);
    }

    return maxi;
}

// tabulation
#include <bits/stdc++.h>

using namespace std;

int getMaxUtil(int n, int m, vector<vector<int>> &matrix,
               vector<vector<int>> &dp)
{

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < m; col++)
        {
            if (row == 0)
            {
                dp[row][col] = matrix[row][col];
                continue;
            }
            int up = matrix[row][col] + dp[row - 1][col];
            int leftDiagonal = col > 0 ? (matrix[row][col] + dp[row - 1][col - 1]) : -1e9;
            int rightDiagonal = col < m - 1 ? (matrix[row][col] + dp[row - 1][col + 1]) : -1e9;
            dp[row][col] = max(up, max(leftDiagonal, rightDiagonal));
        }
    }
    int maxi = INT_MIN;
    for (int i = 0; i < m; i++)
    {
        maxi = max(maxi, dp[n - 1][i]);
    }
    return maxi;
}

int getMaxPathSum(vector<vector<int>> &matrix)
{

    int n = matrix.size();
    int m = matrix[0].size();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    return getMaxUtil(n, m, matrix, dp);
}
