// recursion

int f(int idx, int W, int cost[], int N)
{
    if (idx == N && W != 0)
    {
        return 1e9;
    }
    if (W == 0)
        return 0;

    int pick = 1e8;
    if (W - (idx + 1) >= 0)
        pick = cost[idx] + f(idx, W - (idx + 1), cost, N);
    int notPick = f(idx + 1, W, cost, N);
    return min(pick, notPick);
}
int minimumCost(int cost[], int N, int W)
{
    int result = f(0, W, cost, N, dp);
    if (result != 1e8)
        return result;
    return -1;
}

// memoization

int f(int idx, int W, int cost[], int N, vector<vector<int>> &dp)
{
    if (idx == N && W != 0)
    {
        return 1e9;
    }
    if (W == 0)
        return 0;
    if (dp[idx][W] != -1)
        return dp[idx][W];
    int pick = 1e8;
    if (W - (idx + 1) >= 0 && cost[idx] != -1)
        pick = cost[idx] + f(idx, W - (idx + 1), cost, N, dp);
    int notPick = f(idx + 1, W, cost, N, dp);
    return dp[idx][W] = min(pick, notPick);
}
int minimumCost(int cost[], int N, int W)
{
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, -1));
    int result = f(0, W, cost, N, dp);
    if (result != 1e8)
        return result;
    return -1;
}