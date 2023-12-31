vector<int> max_of_subarrays(vector<int> arr, int n, int k)
{
    vector<int> ans;
    deque<int> dq;
    for (int i = 0; i < n; i++)
    {
        // if front element in queue is not in the current window, we remove it
        if (!dq.empty() && dq.front() <= (i - k))
            dq.pop_front();
        //  maintaining decreasing order
        while (!dq.empty() && arr[dq.back()] <= arr[i])
        {
            dq.pop_back();
        }
        // push all the elements
        dq.push_back(i);
        if (i >= k - 1)
            ans.push_back(arr[dq.front()]);
    }
    return ans;
}