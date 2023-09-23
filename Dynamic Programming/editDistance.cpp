// recursion
int f(int i, int j, int n, int m, string str1, string str2)
{
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;
    if (str1[i] == str2[j])
        return 0 + f(i - 1, j - 1, n, m, str1, str2);

    // delete a character
    int deleteChar = 1 + f(i - 1, j, n, m, str1, str2);
    // replace a character
    int replace = 1 + f(i - 1, j - 1, n, m, str1, str2);
    // insert a character
    int insert = 1 + f(i, j - 1, n, m, str1, str2);

    return min(deleteChar, min(replace, insert));
}

int editDistance(string str1, string str2)
{
    int n = str1.length();
    int m = str2.length();
    return f(n - 1, m - 1, n, m, str1, str2);
}

// memoization

int f(int i, int j, int n, int m, string str1, string str2, vector<vector<int>> &dp)
{
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;
    if (str1[i] == str2[j])
        return 0 + f(i - 1, j - 1, n, m, str1, str2, dp);
    if (dp[i][j] != -1)
        return dp[i][j];
    // delete a character
    int deleteChar = 1 + f(i - 1, j, n, m, str1, str2, dp);
    // replace a character
    int replace = 1 + f(i - 1, j - 1, n, m, str1, str2, dp);
    // insert a character
    int insert = 1 + f(i, j - 1, n, m, str1, str2, dp);

    return dp[i][j] = min(deleteChar, min(replace, insert));
}

int editDistance(string str1, string str2)
{
    int n = str1.length();
    int m = str2.length();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f(n - 1, m - 1, n, m, str1, str2, dp);
}

// tabulation

int f(int i, int j, int n, int m, string str1, string str2, vector<vector<int>> &dp)
{
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;
    if (str1[i] == str2[j])
        return 0 + f(i - 1, j - 1, n, m, str1, str2, dp);
    if (dp[i][j] != -1)
        return dp[i][j];
    // delete a character
    int deleteChar = 1 + f(i - 1, j, n, m, str1, str2, dp);
    // replace a character
    int replace = 1 + f(i - 1, j - 1, n, m, str1, str2, dp);
    // insert a character
    int insert = 1 + f(i, j - 1, n, m, str1, str2, dp);

    return dp[i][j] = min(deleteChar, min(replace, insert));
}

int editDistance(string str1, string str2)
{
    int n = str1.length();
    int m = str2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i < n + 1; i++)
        dp[i][0] = i;

    for (int j = 0; j < m + 1; j++)
        dp[0][j] = j;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
                dp[i][j] = 0 + dp[i - 1][j - 1];
            else
            {
                // delete a character
                int deleteChar = 1 + dp[i - 1][j];
                // replace a character
                int replace = 1 + dp[i - 1][j - 1];
                // insert a character
                int insert = 1 + dp[i][j - 1];

                dp[i][j] = min(deleteChar, min(replace, insert));
            }
        }
    }
    return dp[n][m];
}
