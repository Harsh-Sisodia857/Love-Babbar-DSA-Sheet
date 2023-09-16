#include <bits/stdc++.h>
using namespace std;

long long int f(vector<long long int> &nums, int size)
{

    vector<long long int> dp(size, -1);
    dp[0] = nums[0];

    for (int i = 1; i < size; i++)
    {
        long long int pick;
        if (i - 2 < 0)
            pick = nums[i];
        else
            pick = nums[i] + dp[i - 2];
        long long int notPick = dp[i - 1];
        dp[i] = max(pick, notPick);
    }

    return dp[size - 1];
}

long long int houseRobber(vector<int> &valueInHouse)
{
    long long int n = valueInHouse.size();
    vector<long long int> temp1;
    vector<long long int> temp2;
    if (n == 1)
        return valueInHouse[0];
    for (long long int i = 0; i < n; i++)
    {
        if (i != 0)
            temp1.push_back(valueInHouse[i]);
        if (i != n - 1)
            temp2.push_back(valueInHouse[i]);
    }
    return max(f(temp1, n - 1), f(temp2, n - 1));
}