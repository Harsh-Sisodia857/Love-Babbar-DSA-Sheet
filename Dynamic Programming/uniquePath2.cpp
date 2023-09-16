// Recursion

int mod = (int)(1e9 + 7);
int f(int row, int col, vector<vector<int>> &mat)
{
    if (row == 0 && col == 0)
        return 1;
    if (row < 0 || col < 0)
        return 0;
    if (row >= 0 && col >= 0 && mat[row][col] == -1)
        return 0;

    int left = 0;
    if (col > 0)
        left = f(row, col - 1, mat);
    int up = 0;
    if (row > 0)
        up = f(row - 1, col, mat);
    return (left + up) % mod;
}

int mazeObstacles(int n, int m, vector<vector<int>> &mat)
{
    return f(n - 1, m - 1, mat);
}

// memoization

int mod = (int)(1e9 + 7);
int f(int row, int col, vector<vector<int>> &mat, vector<vector<int>> &dp)
{
    if (row == 0 && col == 0)
        return 1;
    if (row < 0 || col < 0)
        return 0;
    if (row >= 0 && col >= 0 && mat[row][col] == -1)
        return 0;
    if (dp[row][col] != -1)
        return dp[row][col];
    int left = 0;
    if (col > 0)
        left = f(row, col - 1, mat, dp);
    int up = 0;
    if (row > 0)
        up = f(row - 1, col, mat, dp);
    return dp[row][col] = (left + up) % mod;
}

int mazeObstacles(int n, int m, vector<vector<int>> &mat)
{
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f(n - 1, m - 1, mat, dp);
}

// iterative
int mod = (int)(1e9 + 7);
int f(int row, int col, vector<vector<int>> &mat, vector<vector<int>> &dp)
{

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            // base condition
            if (i == 0 && j == 0)
            {
                dp[0][0] = 1;
                continue;
            }
            if (i >= 0 && j >= 0 && mat[i][j] == -1)
            {
                dp[i][j] = 0;
                continue;
            }
            int left = 0;
            int up = 0;
            if (i > 0)
                up = dp[i - 1][j];
            if (j > 0)
                left = dp[i][j - 1];
            dp[i][j] = (left + up) % mod;
        }
    }

    return (dp[row - 1][col - 1]);
}

int mazeObstacles(int n, int m, vector<vector<int>> &mat)
{
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f(n, m, mat, dp);
}