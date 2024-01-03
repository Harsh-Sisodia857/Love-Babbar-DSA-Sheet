int floorSqrt(int n)
{
    if (n == 1 || n == 0)
        return n;
    long long int low = 1;
    long long int high = n;
    long long int ans = 0;
    while (low <= high)
    {
        long long int mid = low + (high - low) / 2;
        if (mid * mid <= n)
        {
            ans = max(ans, mid);
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}
