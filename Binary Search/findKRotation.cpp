int findKRotation(vector<int> &arr)
{
    // Write your code here.
    int n = arr.size();
    int mini = 1e8;
    int miniIdx = -1;
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        // right part is sorted
        if (arr[mid] <= arr[high])
        {
            if (arr[mid] < mini)
            {
                mini = arr[mid];
                miniIdx = mid;
            }
            high = mid - 1;
        }
        else
        {
            if (arr[low] < mini)
            {
                mini = arr[low];
                miniIdx = low;
            }
            low = mid + 1;
        }
    }
    return miniIdx;
}