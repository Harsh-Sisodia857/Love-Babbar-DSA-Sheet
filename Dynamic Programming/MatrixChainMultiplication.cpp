// recursion
#include <bits/stdc++.h>

int f(int i, int j, vector<int> &arr, int n)
{
    if (i == j)
    {
        return 0; // 0 operation perform
    }
    int mini = 1e9;
    for (int k = i; k < j; k++)
    {
        int NoOfOperation = arr[i - 1] * arr[k] * arr[j] +
                            f(i, k, arr, n) + f(k + 1, j, arr, n);
        mini = min(mini, NoOfOperation);
    }
    return mini;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    return f(1, N - 1, arr, N);
}

// memoization

#include <bits/stdc++.h>

int f(int i, int j, vector<int> &arr, int n, vector<vector<int>> &dp)
{
    if (i == j)
    {
        return 0; // 0 operation perform
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    int mini = 1e9;
    for (int k = i; k < j; k++)
    {
        int NoOfOperation = arr[i - 1] * arr[k] * arr[j] +
                            f(i, k, arr, n, dp) + f(k + 1, j, arr, n, dp);
        mini = min(mini, NoOfOperation);
    }
    return dp[i][j] = mini;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N, vector<int>(N, -1));
    return f(1, N - 1, arr, N, dp);
}

// tabulation

#include <bits/stdc++.h>

int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N, vector<int>(N, 0));
    for (int i = N - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < N; j++)
        {
            int mini = 1e9;
            for (int k = i; k < j; k++)
            {
                int NoOfOperation = (arr[i - 1] * arr[k] * arr[j]) +
                                    dp[i][k] + dp[k + 1][j];
                mini = min(mini, NoOfOperation);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][N - 1];
}