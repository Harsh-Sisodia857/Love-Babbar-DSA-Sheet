#include <bits/stdc++.h>
int maximumProfit(vector<int> &prices)
{
    int mini = prices[0];
    int maxProfit = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        int currProfit = prices[i] - mini;
        maxProfit = max(maxProfit, currProfit);
        mini = min(mini, prices[i]);
    }
    return maxProfit;
}