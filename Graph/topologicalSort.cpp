// Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that for every directed edge u v, vertex u comes before v in the ordering.

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void dfs(int node, vector<int> adj[], vector<bool> &vis, stack<int> &st)
    {
        vis[node] = true;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs(it, adj, vis, st);
            }
        }
        // while returning from recursive call we store the node in stack, stack contains topological sort
        st.push(node);
    }
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<bool> vis(V, false);
        vector<int> ans;
        stack<int> st;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, adj, vis, st);
            }
        }
        while (!st.empty())
        {
            int topEle = st.top();
            //  Topological order :  cout<<topEle<<" ";
            ans.push_back(topEle);
            st.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
int check(int V, vector<int> &res, vector<int> adj[])
{

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++)
    {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++)
    {
        for (int v : adj[i])
        {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++)
        {
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }

    return 0;
}
// 2nd Method

vector<int> topologicalSort(vector<int> adj[], int V)
{
    vector<int> indegree(V, 0);
    vector<int> topoSort;
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }
    // store the node in queue whose indegree is 0
    for (int it = 0; it < V; it++)
    {
        if (indegree[it] == 0)
        {
            q.push(it);
        }
    }

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        topoSort.push_back(frontNode);
        for (auto it : adj[frontNode])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }

    return topoSort;
}
