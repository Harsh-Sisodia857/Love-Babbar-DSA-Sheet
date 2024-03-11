// memoization
class Solution
{
public:
    int f(vector<vector<int>> &matrix, int row, int col, int n, vector<vector<int>> &dp)
    {
        if (row >= n || col >= n || col < 0)
        {
            return INT_MAX;
        }
        if (row == n - 1)
        {
            return (matrix[row][col]);
        }
        if (dp[row][col] != -1)
            return dp[row][col];
        int p1 = 1e9;
        if (row + 1 < n && col - 1 >= 0)
            p1 = matrix[row][col] + f(matrix, row + 1, col - 1, n, dp);
        int p2 = 1e9;
        if (row + 1 < n)
            p2 = matrix[row][col] + f(matrix, row + 1, col, n, dp);
        int p3 = 1e9;
        if (row + 1 < n && col + 1 < n)
            p3 = matrix[row][col] + f(matrix, row + 1, col + 1, n, dp);
        int path = min(p1, min(p2, p3));
        return dp[row][col] = path;
    }
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        int miniAns = INT_MAX;
        for (int i = 0; i < row; i++)
        {
            vector<vector<int>> dp(row, vector<int>(col, -1));
            int ans = f(matrix, 0, i, row, dp);
            cout << ans << endl;
            miniAns = min(miniAns, ans);
        }
        return miniAns;
    }
};

// tabulation
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        int miniAns = INT_MAX;
        int n = row;

        vector<vector<int>> dp(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (i == 0)
                {
                    dp[i][j] = matrix[0][j];
                    continue;
                }
                int p1 = INT_MAX;
                if (j + 1 < col)
                    p1 = matrix[i][j] + dp[i - 1][j + 1];
                int p3 = INT_MAX;
                if (j - 1 >= 0)
                    p3 = matrix[i][j] + dp[i - 1][j - 1];
                int p2 = matrix[i][j] + dp[i - 1][j];
                int path = min(p1, min(p2, p3));
                dp[i][j] = path;
            }
        }
        miniAns = dp[n - 1][0];
        for (int i = 1; i < col; i++)
        {
            miniAns = min(miniAns, dp[n - 1][i]);
        }
        return miniAns;
    }
};