// recursion
int f(int idx, int buy, int cap, vector<int> &prices, int n)
{
    if (idx == n || cap == 0)
    {
        return 0;
    }
    int profit = 0;
    // buy
    if (buy == 1)
    {
        profit = max(-prices[idx] + f(idx + 1, 0, cap, prices, n), f(idx + 1, 1, cap, prices, n));
    }
    else
    {
        // when you sell the stock then your 2nd transaction is completed
        profit = max(prices[idx] + f(idx + 1, 1, cap - 1, prices, n), f(idx + 1, 0, cap, prices, n));
    }
    return profit;
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    return f(0, 1, 2, prices, n);
}

// memoization
#include <vector>
int f(int idx, int buy, int cap, vector<int> &prices, int n, vector<vector<vector<int>>> &dp)
{
    if (idx == n || cap == 0)
    {
        return 0;
    }
    if (dp[idx][buy][cap] != -1)
        return dp[idx][buy][cap];

    int profit = 0;
    // buy
    if (buy == 1)
    {
        profit = max(-prices[idx] + f(idx + 1, 0, cap, prices, n, dp), f(idx + 1, 1, cap, prices, n, dp));
    }
    else
    {
        // when you sell the stock then your 2nd transaction is completed
        profit = max(prices[idx] + f(idx + 1, 1, cap - 1, prices, n, dp), f(idx + 1, 0, cap, prices, n, dp));
    }
    return dp[idx][buy][cap] = profit;
}

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    // f(idx,buy/sell,capacity)
    return f(0, 1, 2, prices, n, dp);
}

// tabulation
#include <vector>

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
    // f(idx,buy/sell,capacity)
    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            // for cap = 0 it is handled under base case
            for (int cap = 1; cap < 3; cap++)
            {
                int profit = 0;
                // buy
                if (buy == 1)
                {
                    profit = max(-prices[idx] + dp[idx + 1][0][cap], 0 + dp[idx + 1][1][cap]);
                }
                else
                {
                    // when you sell the stock then your 2nd transaction is completed
                    profit = max(prices[idx] + dp[idx + 1][1][cap - 1], 0 + dp[idx + 1][0][cap]);
                }
                dp[idx][buy][cap] = profit;
            }
        }
    }
    return dp[0][1][2];
}