long long largestPerimeter(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    // 1 1 2 3 5 12 50
    // 1 2 4 7 12 24 74
    vector<long long> prefixSum(n);
    prefixSum[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + nums[i];
    }
    for (int i = n - 1; i > 1; i--)
    {
        int temp = nums[i];
        long long sum = prefixSum[i - 1];
        if (temp < sum)
        {
            return prefixSum[i];
        }
    }
    return -1;
}