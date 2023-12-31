
pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x)
{
    // Write your code here.
    int smallestElement = -1;
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] >= x)
        {
            smallestElement = a[mid];
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    low = 0;
    high = n - 1;
    int largestElement = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] <= x)
        {
            largestElement = a[mid];
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    pair<int, int> ans = {largestElement, smallestElement};
    return ans;
}