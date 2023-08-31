bool isPowerofTwo(long long n)
{
    if (n == 1 || n == 0)
        return n;
    if ((n & (n - 1)) == 0)
        return 1;
    else
        return 0;
}