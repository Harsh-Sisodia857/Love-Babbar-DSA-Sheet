vector<int> singleNumber(vector<int> nums)
{
    vector<int> ans;
    int set1 = 0, set2 = 0;
    int xorSum = nums[0];
    for (int i = 0; i < nums.size() - 1; i++)
    {
        xorSum ^= nums[i + 1];
    }
    xorSum = ~(xorSum - 1) & (xorSum);
    for (int i = 0; i < nums.size(); i++)
    {
        if (xorSum & nums[i])
            set1 ^= nums[i];
        else
            set2 ^= nums[i];
    }
    ans.push_back(set1);
    ans.push_back(set2);
    return ans;
}