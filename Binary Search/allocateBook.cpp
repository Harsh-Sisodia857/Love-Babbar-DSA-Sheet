bool numberOfStudent(vector<int> &arr, int Currpages, int n, int m)
{
    int student = 0, page = 0;
    for (int i = 0; i < n; i++)
    {
        if (page + arr[i] <= Currpages)
        {
            page += arr[i];
        }
        else
        {
            student++;
            page = arr[i];
        }
    }
    if (student < m)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int findPages(vector<int> &arr, int n, int m)
{
    // Write your code here.
    if (m > n)
    {
        return -1;
    }
    int low = INT_MIN, high = 0;
    for (int i = 0; i < n; i++)
    {
        low = max(low, arr[i]);
        high = high + arr[i];
    }
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (numberOfStudent(arr, mid, n, m))
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