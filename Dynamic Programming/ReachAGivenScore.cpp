
void f(int idx, int sum, int coins[], int &count, long long int n, vector<vector<long long int>> &dp)
{
    if (idx >= 3 || sum > n)
    {
        return;
    }
    if (sum == n)
    {
        count++;
        return;
    }

    f(idx, sum + coins[idx], coins, count, n, dp);
    f(idx + 1, sum, coins, count, n, dp);
}

long long int count(long long int n)
{
    long long int table[n + 1], i;
    memset(table, 0, sizeof(table));
    table[0] = 1;
    vector<vector<long long int>> dp(3 + 1, vector<long long int>(n + 1, -1));
    int coins[3] = {3, 5, 10};
    for (int i = 0; i < 4; i++)
    {
        dp[i][0] = 1;
    }
    int count = 0;
    f(0, 0, coins, count, n, dp);
    table[n] = count;
    return table[n];
}