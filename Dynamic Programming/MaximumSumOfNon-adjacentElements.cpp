// Recursion
#include <bits/stdc++.h>
using namespace std;

int f(vector<int> &nums, int idx)
{
    if (idx == 0)
    {
        return nums[0];
    }
    if (idx < 0)
        return 0;
    int pick = f(nums, idx - 2) + nums[idx];
    int notpick = 0 + f(nums, idx - 1);
    return max(pick, notpick);
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    int s = nums.size();
    return f(nums, s - 1);
}

// memoization
#include <bits/stdc++.h>
using namespace std;

int f(vector<int> &nums, int idx, vector<int> &dp)
{
    if (idx == 0)
    {
        return nums[0];
    }
    if (idx < 0)
        return 0;
    if (dp[idx] != -1)
        return dp[idx];

    int pick = f(nums, idx - 2, dp) + nums[idx];
    int notpick = 0 + f(nums, idx - 1, dp);
    return dp[idx] = max(pick, notpick);
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    int s = nums.size();
    vector<int> dp(s + 1, -1);
    return f(nums, s - 1, dp);
}

// iterative
#include <bits/stdc++.h>
using namespace std;

int f(vector<int> &nums, int size)
{

    vector<int> dp(size, -1);
    dp[0] = nums[0];

    for (int i = 1; i < size; i++)
    {
        int pick;
        if (i - 2 < 0)
            pick = nums[i];
        else
            pick = nums[i] + dp[i - 2];
        int notPick = dp[i - 1];
        dp[i] = max(pick, notPick);
    }

    return dp[size - 1];
}

int maximumNonAdjacentSum(vector<int> &nums)
{
    int s = nums.size();
    return f(nums, s);
}