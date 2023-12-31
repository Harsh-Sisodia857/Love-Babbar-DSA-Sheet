void heapify(vector<int> &arr, int n, int idx)
{
    int largest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < n && arr[largest] < arr[left])
        largest = left;
    if (right < n && arr[largest] < arr[right])
        largest = right;

    if (largest != idx)
    {
        swap(arr[largest], arr[idx]);
        heapify(arr, n, largest);
    }
}
vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m)
{
    vector<int> ans = a;
    for (int i = 0; i < m; i++)
    {
        ans.push_back(b[i]);
    }
    for (int i = (n + m) / 2 - 1; i >= 0; i--)
    {
        heapify(ans, n + m, i);
    }
    return ans;
}