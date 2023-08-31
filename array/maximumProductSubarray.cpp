// Function to find maximum product subarray
long long maxProduct(vector<int> arr, int n)
{
    long long prefix = 1;
    long long suffix = 1;
    long long maxi = INT_MIN;
    if (n == 1)
        return arr[0];
    for (int i = 0; i < n; i++)
    {
        if (prefix == 0)
            prefix = 1;
        if (suffix == 0)
            suffix = 1;
        prefix *= arr[i];
        suffix *= arr[n - 1 - i];
        long long maxiPreSuff = max(prefix, suffix);
        maxi = max(maxi, maxiPreSuff);
    }

    return maxi;
}