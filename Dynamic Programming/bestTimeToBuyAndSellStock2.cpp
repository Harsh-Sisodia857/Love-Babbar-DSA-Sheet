// recursion

long f(int idx, int buy, long *values, int n)
{
    if (idx == n)
    {
        return 0;
    }
    int profit = 0;
    // if you can buy
    if (buy)
    {
        // you have two choices either you buy current stock and not buy it and buy the stock later
        profit = max(-values[idx] + f(idx + 1, 0, values, n), f(idx + 1, 1, values, n));
    }
    else
    {
        // now you have to sell the stock which you have buy, again you have two
        // choices either you can sell it on current day or sell it on other day
        profit = max(values[idx] + f(idx + 1, 1, values, n), f(idx + 1, 0, values, n));
    }
    return profit;
}

long getMaximumProfit(long *values, int n)
{
    // f(idx,buy/sell) --> buy represents with 1 and sell represents with 0
    // initially you can buy
    return f(0, 1, values, n);
}

// memoization
#include <vector>

long f(int idx, int buy, long *values, int n, vector<vector<long>> &dp)
{
    if (idx == n)
    {
        return 0;
    }
    if (dp[idx][buy] != -1)
        return dp[idx][buy];

    // initiall profit is zero
    long profit = 0;

    // if you can buy
    if (buy)
    {
        // you have two choices either you buy current stock and not buy it and buy the stock later
        dp[idx][buy] = profit = max(-values[idx] + f(idx + 1, 0, values, n, dp), f(idx + 1, 1, values, n, dp));
    }
    else
    {
        // now you have to sell the stock which you have buy, again you have two
        // choices either you can sell it on current day or sell it on other day
        dp[idx][buy] = profit = max(values[idx] + f(idx + 1, 1, values, n, dp), f(idx + 1, 0, values, n, dp));
    }
    return dp[idx][buy] = profit;
}

long getMaximumProfit(long *values, int n)
{
    // f(idx,buy/sell) --> buy represents with 1 and sell represents with 0
    // initially you can buy
    vector<vector<long>> dp(n + 1, vector<long>(2, -1));
    return f(0, 1, values, n, dp);
}

// tabulation
#include <vector>

long getMaximumProfit(long *values, int n)
{
    // f(idx,buy/sell) --> buy represents with 1 and sell represents with 0
    // initially you can buy
    vector<vector<long>> dp(n + 1, vector<long>(2, 0));
    dp[n][0] = 0;
    dp[n][1] = 0;

    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            // initiall profit is zero
            long profit = 0;

            // if you can buy
            if (buy)
            {
                // you have two choices either you buy current stock and not buy it and buy the stock later
                dp[idx][buy] = max(-values[idx] + dp[idx + 1][0],
                                   dp[idx + 1][1]);
            }
            else
            {
                // now you have to sell the stock which you have buy, again you have two
                // choices either you can sell it on current day or sell it on other day
                dp[idx][buy] = max(values[idx] + dp[idx + 1][1], dp[idx + 1][0]);
            }
        }
    }

    return dp[0][1];
}
