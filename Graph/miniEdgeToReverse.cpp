//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int dst)
    {
        // Creating adjacency list
        vector<pair<int, int>> adj[n + 1];
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back({v, 0});
            adj[v].push_back({u, 1});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n + 1, INT_MAX);
        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty())
        {
            int cost = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node])
            {
                int neighbour = it.first;
                int wt = it.second;
                if ((cost + wt) < dist[neighbour])
                {
                    dist[neighbour] = cost + wt;
                    pq.push({dist[neighbour], neighbour});
                }
            }
        }
        if (dist[dst] == INT_MAX)
            return -1;
        return dist[dst];
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges(m, vector<int>(2));
        for (auto &j : edges)
            for (auto &i : j)
                cin >> i;
        int src, dst;
        cin >> src >> dst;
        Solution s;
        cout << s.minimumEdgeReversal(edges, n, src, dst) << endl;
    }
    return 0;
}
// } Driver Code Ends