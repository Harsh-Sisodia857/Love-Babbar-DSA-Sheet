long long trappingWater(int arr[], int n)
{
    vector<int> left(n, 0);
    left[0] = arr[0];
    vector<int> right(n, 0);
    right[n - 1] = arr[n - 1];
    long long ans = 0;

    // left mai maximum konsi value hai har ek index ke liye
    for (int i = 1; i < n; i++)
    {
        left[i] = max(arr[i], left[i - 1]);
    }
    // right mai maximum konsi value hai har ek index ke liye
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = max(arr[i], right[i + 1]);
    }
    // water stored is minimum height of left box and right box - (size of current box)
    for (int i = 0; i < n; i++)
    {
        ans += min(left[i], right[i]) - arr[i];
    }
    return ans;
}