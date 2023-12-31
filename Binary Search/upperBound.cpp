int upperBound(vector<int> &arr, int x, int n)
{
    int left = 0;
    int right = n - 1;
    int ans = n;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] > x)
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return ans;
}