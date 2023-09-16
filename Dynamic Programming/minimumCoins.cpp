// recursion
#include <bits/stdc++.h> 

int f(int idx,vector<int> coins,int p){
    if(idx == 0){
        if(p % coins[idx] == 0)
            return p/coins[idx];
        return 1e9;
    }
    // not pick
    int notPick = 0 + f(idx-1,coins,p);
    // pick
    int pick = 1e9;
    if(p >= coins[idx])
        pick = 1 + f(idx,coins,p-coins[idx]);
    return min(pick,notPick);
}

int minimumCoins(int p)
{
    vector<int> coins = {1000,500,100,50,20,10,5,2,1};
    int n = coins.size();
    return f(n-1,coins,p);
}

// memoization
#include <bits/stdc++.h> 

int f(int idx,vector<int> coins,int p,vector<vector<int>> &dp){
    int n = coins.size();
    if(idx == 0){
        if(p % coins[idx] == 0)
            return p/coins[idx];
        return 1e9;
    }
    if(dp[idx][p] != -1)
        return dp[idx][p];
    // not pick
    int notPick = 0 + f(idx-1,coins,p,dp);
    // pick
    int pick = 1e9;
    if(p >= coins[idx])
        pick = 1 + f(idx,coins,p-coins[idx],dp);
    return dp[idx][p] = min(pick,notPick);
}

int minimumCoins(int p)
{
    vector<int> coins = {1000,500,100,50,20,10,5,2,1};
    int n = coins.size();
    vector<vector<int>> dp(n,vector<int> (p+1,-1));
    return f(n-1,coins,p,dp);
}

// tabulation
#include <bits/stdc++.h>

int f(int idx, vector<int> coins, int p, vector<vector<int>> &dp)
{
    int n = coins.size();
    if (idx == 0)
    {
        if (p % coins[idx] == 0)
            return p / coins[idx];
        return 1e9;
    }
    if (dp[idx][p] != -1)
        return dp[idx][p];
    // not pick
    int notPick = 0 + f(idx - 1, coins, p, dp);
    // pick
    int pick = 1e9;
    if (p >= coins[idx])
        pick = 1 + f(idx, coins, p - coins[idx], dp);
    return dp[idx][p] = min(pick, notPick);
}

int minimumCoins(int p)
{
    vector<int> coins = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(p + 1, 0));
    // base case
    for (int i = 0; i < p + 1; i++)
    {
        if (i % coins[0] == 0)
            dp[0][i] = (i / coins[0]);
        else
            dp[0][i] = 1e9;
    }
    for (int idx = 1; idx < n; idx++)
    {
        for (int tar = 0; tar < p + 1; tar++)
        {
            // not pick
            int notPick = 0 + dp[idx - 1][tar];
            // pick
            int pick = 1e9;
            if (tar >= coins[idx])
                pick = 1 + dp[idx][tar - coins[idx]];
            dp[idx][tar] = min(pick, notPick);
        }
    }
    return dp[n - 1][p];
}
