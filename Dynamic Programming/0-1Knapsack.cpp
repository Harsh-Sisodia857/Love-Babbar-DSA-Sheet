// recursion
#include <bits/stdc++.h>

int f(int idx, vector<int> weight, vector<int> value, int W)
{
    if (idx == 0)
    {
        if (W >= weight[0])
            return value[0];
        return 0;
    }
    // pick
    int pick = INT_MIN;
    if (W >= weight[idx])
        pick = value[idx] + f(idx - 1, weight, value, W - weight[idx]);
    // not pick
    int notPick = 0 + f(idx - 1, weight, value, W);
    return max(pick, notPick);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    return f(n - 1, weight, value, maxWeight);
}

// memoization
#include <bits/stdc++.h>

int f(int idx, vector<int> weight, vector<int> value, int W, vector<vector<int>> &dp)
{
    if (idx == 0)
    {
        if (W >= weight[0])
            return value[0];
        return 0;
    }
    if (dp[idx][W] != -1)
        return dp[idx][W];
    // pick
    int pick = INT_MIN;
    if (W >= weight[idx])
        pick = value[idx] + f(idx - 1, weight, value, W - weight[idx], dp);
    // not pick
    int notPick = 0 + f(idx - 1, weight, value, W, dp);
    return dp[idx][W] = max(pick, notPick);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    return f(n - 1, weight, value, maxWeight, dp);
}

// iteration

#include <bits/stdc++.h>

int f(int idx, vector<int> weight, vector<int> value, int W, vector<vector<int>> &dp)
{
    if (idx == 0)
    {
        if (W >= weight[0])
            return value[0];
        return 0;
    }
    if (dp[idx][W] != -1)
        return dp[idx][W];
    // pick
    int pick = INT_MIN;
    if (W >= weight[idx])
        pick = value[idx] + f(idx - 1, weight, value, W - weight[idx], dp);
    // not pick
    int notPick = 0 + f(idx - 1, weight, value, W, dp);
    return dp[idx][W] = max(pick, notPick);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));

    // base condition --> if weight at index 0 is lesser than max weight
    for (int i = weight[0]; i <= maxWeight; i++)
    {
        dp[0][i] = value[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < maxWeight + 1; j++)
        {
            // pick
            int pick = INT_MIN;
            if (j >= weight[i])
                pick = value[i] + dp[i - 1][j - weight[i]];
            // not pick
            int notPick = 0 + dp[i - 1][j];
            dp[i][j] = max(pick, notPick);
        }
    }
    return dp[n - 1][maxWeight];
}