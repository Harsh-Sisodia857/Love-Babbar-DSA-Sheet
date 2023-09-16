#include <bits/stdc++.h>

int lcs(string s, string t)
{
    int n = s.length();
    int m = t.length();
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
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
    }
    return dp[n][m];
}

int longestPalindromeSubsequence(string s)
{
    // to find the longest palindrome subsequence, reverse the string and then find the longest common subsequence in the original and reversed string
    string t = s;
    reverse(t.begin(), t.end());
    return lcs(s, t);
}