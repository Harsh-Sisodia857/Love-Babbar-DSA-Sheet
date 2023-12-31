long long countSubArrayProductLessThanK(const vector<int> &a, int n, long long k)
{
    long long p = 1;
    long long res = 0;
    for (int start = 0, end = 0; end < n; end++)
    {
        p = p * a[end];
        while (start < end && p >= k)
            p /= a[start++];
        if (p < k)
        {
            res += (1 + end - start);
        }
    }
    return res;
}