int missingK(vector<int> vec, int n, int k)
{
    int low = 0;
    int high = n - 1;
    for (int i = 0; i < n; i++)
    {
        int mid = low + (high - low) / 2;
        int missing = vec[mid] - (mid + 1);
        if (missing < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return vec[high] + (k - (vec[high] - (high + 1)));
}