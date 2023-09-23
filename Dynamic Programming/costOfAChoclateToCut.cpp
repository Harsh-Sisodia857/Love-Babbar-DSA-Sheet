// recursion

#include <bits/stdc++.h>

int f(int i, int j, vector<int> &cuts)
{
    if (i > j)
        return 0;
    int mini = 1e9;
    for (int idx = i; idx <= j; idx++)
    {
        int cost = (cuts[j + 1] - cuts[i - 1]) + f(i, idx - 1, cuts) + f(idx + 1, j, cuts);
        mini = min(mini, cost);
    }
    return mini;
}
int cost(int n, int c, vector<int> &cuts)
{
    cuts.push_back(n); // lenght of choclate is added
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end()); // to make the cuts independent to each other
    return f(1, c, cuts);
}

// memoization

#include <bits/stdc++.h>

int f(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int mini = 1e9;
    for (int idx = i; idx <= j; idx++)
    {
        int cost = (cuts[j + 1] - cuts[i - 1]) + f(i, idx - 1, cuts, dp) + f(idx + 1, j, cuts, dp);
        mini = min(mini, cost);
    }
    return dp[i][j] = mini;
}
int cost(int n, int c, vector<int> &cuts)
{
    cuts.push_back(n); // lenght of choclate is added
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end()); // to make the cuts independent to each other
    vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));
    return f(1, c, cuts, dp);
}

