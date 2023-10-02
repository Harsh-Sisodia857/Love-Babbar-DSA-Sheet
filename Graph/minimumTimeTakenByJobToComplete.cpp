//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<int> minimumTime(int n, vector<vector<int>> &edges, int m)
    {

        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }

        vector<int> indegree(n + 1);
        queue<int> q;
        for (int i = 1; i <= n; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        vector<int> miniTime(n + 1);
        for (int i = 1; i <= n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
                miniTime[i] = 1;
            }
        }

        // do bfs
        while (!q.empty())
        {
            int topEle = q.front();
            q.pop();

            for (auto it : adj[topEle])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                    miniTime[it] = miniTime[topEle] + 1;
                }
            }
        }
        miniTime.erase(miniTime.begin());
        return miniTime;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int m;
        cin >> m;
        vector<vector<int>> edges(m, vector<int>(2));
        for (int i = 0; i < m; i++)
            cin >> edges[i][0] >> edges[i][1];
        Solution s;
        vector<int> ans = s.minimumTime(n, edges, m);
        for (auto j : ans)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends