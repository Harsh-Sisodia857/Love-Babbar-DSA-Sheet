//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool dfs(int node, vector<bool> &vis, vector<bool> &dfsVis, unordered_map<int, vector<int>> adj)
    {
        vis[node] = true;
        dfsVis[node] = true;

        // visiting neighbour nodes
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                if (dfs(it, vis, dfsVis, adj))
                    return true;
            }
            else if (dfsVis[it])
                return true;
        }
        dfsVis[node] = false;
        return false;
    }

    bool isPossible(int N, int P, vector<pair<int, int>> &prerequisites)
    {
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < prerequisites.size(); i++)
        {
            int u = prerequisites[i].first;
            int v = prerequisites[i].second;
            adj[v].push_back(u);
        }

        // detecting cycle using dfs
        vector<bool> vis(N, false);
        vector<bool> dfsVis(N, false);

        for (int i = 0; i < N; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, vis, dfsVis, adj))
                    return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int N, P;
        vector<pair<int, int>> prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i)
        {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


// 2nd Approach 