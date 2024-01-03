// when unique element is not present 
int search(vector<int> &arr, int n, int k)
{
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == k)
            return mid;

        // if left part is sorted
        if (arr[mid] >= arr[low])
        {
            // is target exist between first half
            if (arr[mid] >= k && arr[low] <= k)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        // else right part is sorted
        else{
            if (arr[mid] <= arr[high])
            {
                if (arr[mid] <= k && arr[high] >= k)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
    }
    return -1;
}

// when unique element is present

bool searchInARotatedSortedArrayII(vector<int> &arr, int target)
{
    // Write your code here.
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
            return true;
        if (arr[low] == arr[mid] && arr[mid] == arr[high])
        {
            low++;
            high--;
            continue;
        }
        // left is sorted
        if (arr[low] <= arr[mid])
        {
            if (arr[mid] >= target && arr[low] <= target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        // right is sorted
        else
        {
            if (arr[mid] <= arr[high])
            {
                if (arr[mid] <= target && arr[high] >= target)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
    }
    return false;
}
