// recursion

int f(int start, int end, vector<int> &arr, int k)
{
    if (start >= end)
        return 0;
    if (arr[end] - arr[start] <= k)
        return 0;
    return 1 + min(f(start + 1, end, arr, k), f(start, end - 1, arr, k));
}
int removals(vector<int> &arr, int k)
{
    sort(arr.begin(), arr.end());
    int n = arr.size();
    return f(0, n - 1, arr, k);
}

// memoization

int f(int start, int end, vector<int> &arr, int k, vector<vector<int>> &dp)
{
    if (start >= end)
        return 0;
    if (arr[end] - arr[start] <= k)
        return 0;
    if (dp[start][end] != -1)
        return dp[start][end];

    return dp[start][end] = 1 + min(f(start + 1, end, arr, k, dp), f(start, end - 1, arr, k, dp));
}
int removals(vector<int> &arr, int k)
{
    sort(arr.begin(), arr.end());
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return f(0, n - 1, arr, k, dp);
}