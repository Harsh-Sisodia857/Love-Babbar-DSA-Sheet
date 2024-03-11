vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int> ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>> pq;
        for(int i = 0; i < k; i++){
            pq.push({arr[i],i});
        }
        ans.push_back(pq.top().first);
        for(int i = 1; i < n-k+1; i++){
            pq.push({arr[i+k-1],i+k-1});
            while (!pq.empty() && pq.top().second < i) {
                pq.pop();
            }

            ans.push_back(pq.top().first);
        }
        return ans;
    }