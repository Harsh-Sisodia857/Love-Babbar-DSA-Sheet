int findMaxSubarraySum(long long arr[], int n, long long k)
{
    int start = 0, end = 0, count = 0;
    long long sum = arr[0];
    long long maxi = 0;
    while (start < n && end < n)
    {
        if (sum <= k)
        {
            end++;
            maxi = max(maxi, sum);
            // to avoid adding garbage value
            if (end < n)
                sum += arr[end];
        }
        else
        {
            sum -= arr[start];
            start++;
        }
    }
    return maxi;
}