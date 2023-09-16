// recursion
int f(int idx, vector<int> &price, int N)
{
    if (idx == 0)
    {
        return N * price[0];
    }
    // pick
    int pick = INT_MIN;
    // index represent rod length
    if (N >= (idx + 1))
        pick = price[idx] + f(idx, price, N - (idx + 1));
    // not pick
    int notPick = 0 + f(idx - 1, price, N);
    return max(pick, notPick);
}

int cutRod(vector<int> &price, int n)
{
    return f(n - 1, price, n);
}

// memoization
int f(int idx, vector<int> &price, int N, vector<vector<int>> &dp)
{
    if (idx == 0)
    {
        return N * price[0];
    }
    if (dp[idx][N] != -1)
        return dp[idx][N];
    // pick
    int pick = INT_MIN;
    // index represent rod length
    if (N >= (idx + 1))
        pick = price[idx] + f(idx, price, N - (idx + 1), dp);
    // not pick
    int notPick = 0 + f(idx - 1, price, N, dp);
    return dp[idx][N] = max(pick, notPick);
}

int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return f(n - 1, price, n, dp);
}

// tabulation
int f(int idx, vector<int> &price, int N, vector<vector<int>> &dp)
{
    if (idx == 0)
    {
        return N * price[0];
    }
    if (dp[idx][N] != -1)
        return dp[idx][N];
    // pick
    int pick = INT_MIN;
    // index represent rod length
    if (N >= (idx + 1))
        pick = price[idx] + f(idx, price, N - (idx + 1), dp);
    // not pick
    int notPick = 0 + f(idx - 1, price, N, dp);
    return dp[idx][N] = max(pick, notPick);
}

int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    for (int i = 0; i <= n; i++)
        dp[0][i] = i * price[0];
    for (int idx = 1; idx < n; idx++)
    {
        for (int len = 0; len <= n; len++)
        {
            // pick
            int pick = INT_MIN;
            // index represent rod length
            if (len >= (idx + 1))
                pick = price[idx] + dp[idx][len - (idx + 1)];
            // not pick
            int notPick = 0 + dp[idx - 1][len];
            dp[idx][len] = max(pick, notPick);
        }
    }
    return dp[n - 1][n];
}
