vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    set<vector<int>> combo;
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;
            int left = j + 1;
            int right = n - 1;
            long long currSum = nums[i] + nums[j];
            while (left < right)
            {
                if ((currSum + nums[left] + nums[right]) == target)
                {
                    combo.insert({nums[i], nums[j], nums[left], nums[right]});
                    left++;
                    right--;
                }
                else if ((currSum + nums[left] + nums[right]) > target)
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }
    }
    for (auto &it : combo)
    {
        ans.push_back(vector<int>(it.begin(), it.end()));
    }

    return ans;
}