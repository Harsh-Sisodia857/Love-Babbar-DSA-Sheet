int getMax(vector<int> &arr, int n)
{
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
    }
    return maxi;
}

int getDivisor(vector<int> &arr, int currDivisor, int limit)
{
    int n = arr.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count += ceil((double)arr[i] / (double)currDivisor);
    }
    if (count <= limit)
    {
        return 1;
    }
    return 0;
}

int smallestDivisor(vector<int> &arr, int limit)
{
    int n = arr.size();
    int low = 1;
    int high = getMax(arr, n);

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int isPossible = getDivisor(arr, mid, limit);
        if (isPossible)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}