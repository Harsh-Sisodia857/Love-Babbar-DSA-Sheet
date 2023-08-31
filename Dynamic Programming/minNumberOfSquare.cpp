#include<bits/stdc++.h>
using namespace std;

// using recursion

// int minSquare(int n)
// {
//     if (n == 0)
//         return 0;
//     if(n == 1)
//         return 1;
//     int ans = INT_MAX;
//     for (int i = 1; i * i <= n; i++)
//     {
//         ans = min(minSquare(n - (i * i)), ans);
//     }

//     return ans+1;
// }

// int main()
// {
//     int n = 4;
//     cout << minSquare(n) << endl;
//     return 0;
// }

// iterative

int minSquare(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 1; i <= n; i++)
    {
        int minAns = INT_MAX;
        for (int j = 1; j * j <= i; j++)
        {
            int ans = dp[i - (j * j)];
            minAns = min(ans, minAns);
        }
        dp[i] = minAns + 1;
    }

    return dp[n];
}

int main()
{
    int n = 41;
    cout << minSquare(n) << endl;
    return 0;
}