int subarraySum(vector<int>& nums, int k) {
        int prefixSum = 0;
        int res = 0;
        unordered_map<int,int> m;
        for(int i = 0; i < nums.size(); i++){
            prefixSum += nums[i];
            if(prefixSum == k)
                res++;
            if(m.find(prefixSum - k) != m.end())
                res += m[prefixSum-k];
             m[prefixSum]++;
        }
        return res;
    }