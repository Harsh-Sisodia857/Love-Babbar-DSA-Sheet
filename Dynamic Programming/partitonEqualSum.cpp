// Recursion
bool partitionUtils(vector<int> &arr, int idx, int target)
{
    if (idx == 0)
    {
        return arr[idx] == target;
    }
    if (target == 0)
        return true;
    bool left = false;
    if (arr[idx] <= target)
        left = partitionUtils(arr, idx - 1, target - arr[idx]);
    bool right = partitionUtils(arr, idx - 1, target);
    return left || right;
}

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
    return partitionUtils(arr, n - 1, k);
}

// memoization
bool partitionUtils(vector<int> &arr, int idx, int target, vector<vector<int>> &dp)
{
    if (idx == 0)
    {
        return arr[idx] == target;
    }
    if (target == 0)
        return true;
    if (dp[idx][target] != -1)
        return dp[idx][target];
    bool left = false;
    if (arr[idx] <= target)
        left = partitionUtils(arr, idx - 1, target - arr[idx], dp);
    bool right = partitionUtils(arr, idx - 1, target, dp);
    return dp[idx][target] = left || right;
}

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
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return partitionUtils(arr, n - 1, k, dp);
}

// tabulation
