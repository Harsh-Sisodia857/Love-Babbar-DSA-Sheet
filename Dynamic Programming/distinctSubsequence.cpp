// recursion

int mod = 1e9 + 7;
int f(int i, int j, string &str, string &sub)
{
    // base case
    if (j < 0)
    {
        return 1;
    }
    if (i < 0)
    {
        return 0;
    }

    if (str[i] == sub[j])
    {
        return (f(i - 1, j - 1, str, sub) + f(i - 1, j, str, sub)) % mod;
    }
    return f(i - 1, j, str, sub);
}

int distinctSubsequences(string &str, string &sub)
{
    int n = str.size();
    int m = sub.size();
    return f(n - 1, m - 1, str, sub);
}

// memoization

int mod = 1e9 + 7;
int f(int i, int j, string &str, string &sub, vector<vector<int>> &dp)
{
    // base case
    if (j < 0)
    {
        return 1;
    }
    if (i < 0)
    {
        return 0;
    }
    if (dp[i][j] != -1)
        return dp[i][j];

    if (str[i] == sub[j])
    {
        return dp[i][j] = (f(i - 1, j - 1, str, sub, dp) + f(i - 1, j, str, sub, dp)) % mod;
    }
    return dp[i][j] = f(i - 1, j, str, sub, dp);
}

int distinctSubsequences(string &str, string &sub)
{
    int n = str.size();
    int m = sub.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return f(n - 1, m - 1, str, sub, dp);
}

// tabulation

int mod = 1e9 + 7;
int f(int i, int j, string &str, string &sub, vector<vector<int>> &dp)
{
    // base case
    if (j < 0)
    {
        return 1;
    }
    if (i < 0)
    {
        return 0;
    }
    if (dp[i][j] != -1)
        return dp[i][j];

    if (str[i] == sub[j])
    {
        return dp[i][j] = (f(i - 1, j - 1, str, sub, dp) + f(i - 1, j, str, sub, dp)) % mod;
    }
    return dp[i][j] = f(i - 1, j, str, sub, dp);
}

int distinctSubsequences(string &str, string &sub)
{
    int n = str.size();
    int m = sub.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // base case
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (str[i - 1] == sub[j - 1])
            {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][m];
}
