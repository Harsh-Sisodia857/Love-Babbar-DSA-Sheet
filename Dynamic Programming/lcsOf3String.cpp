int lcs(string s1, string s2, string s3, int n1, int n2, int n3, int dp[][100][100])
{
    if (n1 == 0 || n2 == 0 || n3 == 0)
        return 0;
    if (dp[n1][n2][n3] != -1)
        return dp[n1][n2][n3];
    if (s1[n1 - 1] == s2[n2 - 1] && s2[n2 - 1] == s3[n3 - 1])
    {
        return 1 + lcs(s1, s2, s3, n1 - 1, n2 - 1, n3 - 1, dp);
    }
    return dp[n1][n2][n3] = max({lcs(s1, s2, s3, n1 - 1, n2, n3, dp),
                                 lcs(s1, s2, s3, n1, n2 - 1, n3, dp), lcs(s1, s2, s3, n1, n2, n3 - 1, dp)});
}

int LCSof3(string A, string B, string C, int n1, int n2, int n3)
{
    int dp[n1 + 1][100][100];
    memset(dp, -1, sizeof(dp));
    return lcs(A, B, C, n1, n2, n3, dp);
}