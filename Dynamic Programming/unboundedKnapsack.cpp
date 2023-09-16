// recursion
int f(int idx, int w, vector<int> &profit, vector<int> &weight)
{
    if (idx == 0)
    {
        if (w % weight[0] == 0)
        {
            return (w / weight[0]) * profit[0];
        }
        return 0;
    }
    // not pick
    int notPick = 0 + f(idx - 1, w, profit, weight);
    // pick
    int pick = 0;
    if (w >= weight[idx])
        pick = profit[idx] + f(idx, w - weight[idx], profit, weight);
    return max(pick, notPick);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    return f(n - 1, w, profit, weight);
}

// memoization
int f(int idx, int w, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp)
{
    if (idx == 0)
    {
        if (w % weight[0] == 0)
        {
            return (w / weight[0]) * profit[0];
        }
        return 0;
    }
    if (dp[idx][w] != -1)
        return dp[idx][w];
    // not pick
    int notPick = 0 + f(idx - 1, w, profit, weight, dp);
    // pick
    int pick = 0;
    if (w >= weight[idx])
        pick = profit[idx] + f(idx, w - weight[idx], profit, weight, dp);
    return dp[idx][w] = max(pick, notPick);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    return f(n - 1, w, profit, weight, dp);
}

// tabulation
int f(int idx, int w, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp)
{
    if (idx == 0)
    {
        if (w % weight[0] == 0)
        {
            return (w / weight[0]) * profit[0];
        }
        return 0;
    }
    if (dp[idx][w] != -1)
        return dp[idx][w];
    // not pick
    int notPick = 0 + f(idx - 1, w, profit, weight, dp);
    // pick
    int pick = 0;
    if (w >= weight[idx])
        pick = profit[idx] + f(idx, w - weight[idx], profit, weight, dp);
    return dp[idx][w] = max(pick, notPick);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n, vector<int>(w + 1, 0));
    // base case
    for (int i = weight[0]; i <= w; i++)
        dp[0][i] = (i / weight[0]) * profit[0];

    for (int idx = 1; idx < n; idx++)
    {
        for (int j = 0; j <= w; j++)
        {
            // not pick
            int notPick = 0 + dp[idx - 1][j];
            // pick
            int pick = -1e9;
            if (j >= weight[idx])
                pick = profit[idx] + dp[idx][j - weight[idx]];
            dp[idx][j] = max(pick, notPick);
        }
    }
    return dp[n - 1][w];
}