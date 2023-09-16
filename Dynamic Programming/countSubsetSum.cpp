// recursion
int mod = 1e9 + 7;
int f(int idx, vector<int> &arr, int k)
{
    if (k == 0)
        return 1;
    if (idx == 0)
    {
        return (arr[0] == k) ? 1 : 0;
    }
    if (idx < 0)
        return 0;
    // pick
    int pick = 0;
    if (arr[idx] <= k)
        pick = f(idx - 1, arr, k - arr[idx]);
    // not pick
    int notPick = f(idx - 1, arr, k);
    return (pick + notPick) % mod;
}

int findWays(vector<int> &arr, int k)
{
    int n = arr.size();
    return f(n - 1, arr, k);
}

// memoization
int mod = 1e9 + 7;
int f(int idx, vector<int> &arr, int k, vector<vector<int>> &dp)
{
    if (k == 0)
        return 1;
    if (idx == 0)
    {
        return (arr[0] == k) ? 1 : 0;
    }
    if (idx < 0)
        return 0;
    if (dp[idx][k] != -1)
        return dp[idx][k];
    // pick
    int pick = 0;
    if (arr[idx] <= k)
        pick = f(idx - 1, arr, k - arr[idx], dp);
    // not pick
    int notPick = f(idx - 1, arr, k, dp);
    return dp[idx][k] = (pick + notPick) % mod;
}

int findWays(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return f(n - 1, arr, k, dp);
}

// tabulation
int mod = 1e9 + 7;
int f(int idx, vector<int> &arr, int k, vector<vector<int>> &dp)
{
    if (k == 0)
        return 1;
    if (idx == 0)
    {
        return (arr[0] == k) ? 1 : 0;
    }
    if (idx < 0)
        return 0;
    if (dp[idx][k] != -1)
        return dp[idx][k];
    // pick
    int pick = 0;
    if (arr[idx] <= k)
        pick = f(idx - 1, arr, k - arr[idx], dp);
    // not pick
    int notPick = f(idx - 1, arr, k, dp);
    return dp[idx][k] = (pick + notPick) % mod;
}

int findWays(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    // base conditions
    for (int i = 0; i < n; i++)
        dp[i][0] = 1;
    if (arr[0] <= k)
        dp[0][arr[0]] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            int pick = 0;
            if (arr[i] <= j)
                pick = dp[i - 1][j - arr[i]];
            // not pick
            int notPick = dp[i - 1][j];
            dp[i][j] = (pick + notPick) % mod;
        }
    }
    return dp[n - 1][k];
}
