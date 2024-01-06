int checkForBloomed(vector<int> arr, int currDay, int k)
{
    int n = arr.size();
    int count = 0;
    int bouquets = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= currDay)
        {
            count++;
        }
        else
        {
            bouquets += (count / k);
            count = 0;
        }
    }
    bouquets += (count / k);
    return bouquets;
}

int roseGarden(vector<int> arr, int k, int m)
{
    int n = arr.size();
    if (m * k > n)
    {
        return -1;
    }
    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }

    int low = mini;
    int high = maxi;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int count = checkForBloomed(arr, mid, k);
        if (count >= m)
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