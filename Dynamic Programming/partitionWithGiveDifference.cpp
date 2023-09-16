// Recursion
#include <bits/stdc++.h>
int mod = (1e9 + 7);
int f(int idx, vector<int> &arr, int target)
{
    if (idx == 0)
    {
        if (target == 0 && arr[0] == 0)
            return 2;
        if (target == 0 || arr[0] == target)
            return 1;
        return 0;
    }

    int pick = 0;
    if (target >= arr[idx])
        pick = f(idx - 1, arr, target - arr[idx]);
    int notPick = f(idx - 1, arr, target);
    return (pick + notPick) % mod;
}

int countPartitions(int n, int d, vector<int> &arr)
{
    // s1 + s2 = totalSum
    // s1 - s2 = d; s1 > s2
    // (totalSum - s2) - s2 = d
    // totalSum - d = 2s2
    // s2 = totalSum - d/2
    // now question changes to that we have to find out no. of subset = totalSum - d/2
    int totalSum = 0;
    for (int i = 0; i < n; i++)
        totalSum += arr[i];

    int target = (totalSum - d) / 2;
    // some base condition
    if (totalSum - d < 0 || (totalSum - d) % 2 != 0)
        return 0;

    return f(n - 1, arr, target);
}

// memoization
#include <bits/stdc++.h>
int mod = (1e9 + 7);
int f(int idx, vector<int> &arr, int target, vector<vector<int>> &dp)
{
    if (idx == 0)
    {
        if (target == 0 && arr[0] == 0)
            return 2;
        if (target == 0 || arr[0] == target)
            return 1;
        return 0;
    }
    if (dp[idx][target] != -1)
        return dp[idx][target];

    int pick = 0;
    if (target >= arr[idx])
        pick = f(idx - 1, arr, target - arr[idx], dp);
    int notPick = f(idx - 1, arr, target, dp);
    return dp[idx][target] = (pick + notPick) % mod;
}

int countPartitions(int n, int d, vector<int> &arr)
{
    // s1 + s2 = totalSum
    // s1 - s2 = d; s1 > s2
    // (totalSum - s2) - s2 = d
    // totalSum - d = 2s2
    // s2 = totalSum - d/2
    // now question changes to that we have to find out no. of subset = totalSum - d/2
    int totalSum = 0;
    for (int i = 0; i < n; i++)
        totalSum += arr[i];

    int target = (totalSum - d) / 2;
    // some base condition
    if (totalSum - d < 0 || (totalSum - d) % 2 != 0)
        return 0;
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return f(n - 1, arr, target, dp);
}

#include <bits/stdc++.h>
int mod = (1e9 + 7);
int f(int idx, vector<int> &arr, int target, vector<vector<int>> &dp)
{
    if (idx == 0)
    {
        if (target == 0 && arr[0] == 0)
            return 2;
        if (target == 0 || arr[0] == target)
            return 1;
        return 0;
    }
    if (dp[idx][target] != -1)
        return dp[idx][target];

    int pick = 0;
    if (target >= arr[idx])
        pick = f(idx - 1, arr, target - arr[idx], dp);
    int notPick = f(idx - 1, arr, target, dp);
    return dp[idx][target] = (pick + notPick) % mod;
}

int countPartitions(int n, int d, vector<int> &arr)
{
    // s1 + s2 = totalSum
    // s1 - s2 = d; s1 > s2
    // (totalSum - s2) - s2 = d
    // totalSum - d = 2s2
    // s2 = totalSum - d/2
    // now question changes to that we have to find out no. of subset = totalSum - d/2
    int totalSum = 0;
    for (int i = 0; i < n; i++)
        totalSum += arr[i];

    int target = (totalSum - d) / 2;

    // some base condition
    if (totalSum - d < 0 || (totalSum - d) % 2 != 0)
        return 0;
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    // base condition for tabulation
    if (arr[0] == 0)
        dp[0][arr[0]] = 2; // idx is 0 and arr[idx] is also 0 and target is 0
    else
        dp[0][0] = 1;                    // idx is 0, arr[idx] is not equal to 0 and target is 0
    if (arr[0] != 0 && arr[0] <= target) // arr[0] <= target this condition ensure that there is not out of bound
        dp[0][arr[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            int pick = 0;
            if (j >= arr[i])
                pick = dp[i - 1][j - arr[i]];
            int notPick = dp[i - 1][j];
            dp[i][j] = (pick + notPick) % mod;
        }
    }

    return dp[n - 1][target];
}
