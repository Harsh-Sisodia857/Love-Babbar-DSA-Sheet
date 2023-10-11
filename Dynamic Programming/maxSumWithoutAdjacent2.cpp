int findMaxSum(vector<int> &arr)
{
    int n = arr.size();
    vector<int> sum(n, 0);
    sum[0] = arr[0];
    sum[1] = arr[1] + arr[0];
    sum[2] = max(sum[1], max(sum[0] + arr[2], arr[1] + arr[2]));
    for (int i = 3; i < n; i++)
    {
        // exculding current index -- arr[i], sum[i-1]
        // excluding prev index -- sum[i-2] + arr[i]
        // excluding prev to prev index -- sum[i-3] + arr[i-1] + arr[i]
        sum[i] = max(max(sum[i - 1], sum[i - 2] + arr[i]), sum[i - 3] + arr[i - 1] + arr[i]);
    }
    return sum[n - 1];
}