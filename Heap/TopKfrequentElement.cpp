vector<int> topK(vector<int> &nums, int k)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>> pq;
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
    {
        m[nums[i]]++;
    }
    for (auto it : m)
    {
        pq.push({it.second, it.first});
    }
    vector<int> ans;
    for (int i = 0; i < k; i++)
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}