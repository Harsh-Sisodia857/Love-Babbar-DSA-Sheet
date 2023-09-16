// Recursion
#include <bits/stdc++.h>

bool f(int idx, int target, vector<int> &arr, int n)
{
    if (target == 0)
        return true;
    if (idx == n - 1)
    {
        return arr[idx] == target;
    }

    // pick
    bool pick = false;
    if (arr[idx] <= target)
        pick = f(idx + 1, target - arr[idx], arr, n);
    // not pick
    bool notPick = f(idx + 1, target, arr, n);
    
    return pick || notPick;
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    return f(0, k, arr, n);
}

// memoization
bool subsetSumUtil(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;

    if (ind == 0)
        return arr[0] == target;

    if (dp[ind][target] != -1)
        return dp[ind][target];

    bool notTaken = subsetSumUtil(ind - 1, target, arr, dp);

    bool taken = false;
    if (arr[ind] <= target)
        taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);

    return dp[ind][target] = notTaken || taken;
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));

    return subsetSumUtil(n - 1, k, arr, dp);
}

// tabulation
bool subsetSumUtil(int n, int k, vector<int> &arr, vector<vector<int>> &dp)
{

    for (int i = 0; i < n; i++)
        dp[i][0] = 1;
    if (arr[0] <= k)
        dp[0][arr[0]] = k;
    for (int i = 1; i < dp.size(); i++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool notTaken = dp[i - 1][target];
            bool taken = false;
            if (arr[i] <= target)
                taken = dp[i - 1][target - arr[i]];
            dp[i][target] = taken || notTaken;
        }
    }

    return dp[n - 1][k];
}

bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    return subsetSumUtil(n, k, arr, dp);
}

// iterative
bool canPartition(vector<int> &arr, int n)
{
    int totalSum = 0;
    for (int i = 0; i < n; i++)
    {
        totalSum += arr[i];
    }
    if (totalSum % 2 != 0)
        return false;
    int k = totalSum / 2;
    vector<vector<int>> dp(n, vector<int>(k + 1, false));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    if (arr[0] <= k)
        dp[0][arr[0]] = true;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < k + 1; j++)
        {
            bool left = false;
            if (arr[i] <= j)
                left = dp[i - 1][j - arr[i]];
            bool right = dp[i - 1][j];
            dp[i][j] = left || right;
        }
    }
    return dp[n - 1][k];
}
