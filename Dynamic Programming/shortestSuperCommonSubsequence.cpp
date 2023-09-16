// if we want to find the length of supersequence then it will be : lenght(a) + length(b) - lcs(a,b);
#include <bits/stdc++.h>
string shortestSupersequence(string a, string b)
{
    // lcs
    int n = a.length();
    int m = b.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < m + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                if (a[i - 1] == b[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
    }
    int len = dp[n][m];
    int i = n, j = m;
    int index = len - 1;
    string ans = "";
    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            ans += a[i - 1];
            index--;
            i--;
            j--;
        }
        else
        {
            if (dp[i][j - 1] > dp[i - 1][j])
            {
                ans += b[j - 1];
                j--;
            }
            else
            {
                ans += a[i - 1];
                i--;
            }
        }
    }
    while (i > 0)
    {
        ans += a[i - 1];
        i--;
    }
    while (j > 0)
    {
        ans += b[j - 1];
        j--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}