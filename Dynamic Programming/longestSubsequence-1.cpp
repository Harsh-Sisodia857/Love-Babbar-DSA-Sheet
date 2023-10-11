int f(int idx, int prev, int N, int A[])
{
    // base case
    if (idx == N)
    {
        return 0;
    }

    // pick
    int pick = 0;
    if (prev == -1 || abs(prev - A[idx]) == 1)
        pick = 1 + f(idx + 1, A[idx], N, A);
    // not pick
    int notPick = f(idx + 1, prev, N, A);
    return max(pick, notPick);
}
int longestSubsequence(int N, int A[])
{
    return f(0, -1, N, A);
}