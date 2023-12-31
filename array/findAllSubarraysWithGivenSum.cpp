// O(n^3) Solution
int findAllSubarraysWithGivenSum(vector<int> &arr, int target)
{
    int count = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }
            if (sum == target)
                count++;
        }
    }
    return count;
}

// O(n^2) Solution
int findAllSubarraysWithGivenSum(vector<int> &arr, int target)
{
    int count = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == target)
                count++;
        }
    }
    return count;
}

// O(n log(n) ) Solution

int findAllSubarraysWithGivenSum(vector<int> &arr, int target)
{
    int count = 0;
    int n = arr.size();
    unordered_map<int, int> m;
    m[0] = 1;
    // calculating prefix sum
    vector<int> prefixSum(n, 0);
    prefixSum[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        int sum = prefixSum[i];
        if (m.find(sum - target) != m.end())
        {
            count += m[sum - target];
        }
        m[sum]++;
    }

    // for(auto it : m)
    //     cout<<it.first<<" "<<it.second<<endl;

    return count;
}