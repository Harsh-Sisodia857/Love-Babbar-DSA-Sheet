
bool isPossible(vector<int> &arr, int sum, int k)
{
    int currSum = 0;
    int noOfPartition = 1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (currSum + arr[i] <= sum)
        {
            currSum += arr[i];
        }
        else
        {
            noOfPartition++;
            currSum = arr[i];
        }
    }
    if (noOfPartition > k)
        return true;
    return false;
}

int largestSubarraySumMinimized(vector<int> a, int k)
{
    // Write Your Code Here
    int low = -1e9;
    int high = 0;
    for (int i = 0; i < a.size(); i++)
    {
        low = max(low, a[i]);
        high += a[i];
    }
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isPossible(a, mid, k))
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}