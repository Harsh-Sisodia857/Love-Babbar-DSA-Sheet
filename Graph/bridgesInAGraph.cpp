int t = 1;

void dfs(int node, int parent, vector<int> adj[], vector<int> &vis, int timer[], int low[], vector<vector<int>> &bridges)
{
    vis[node] = 1;
    timer[node] = t;
    low[node] = t;
    t++;

    for (auto it : adj[node])
    {
        // if the adjacent node is the parent node, ignore it
        if (it == parent)
            continue;

        // if the neighbor is not visited
        if (!vis[it])
        {
            dfs(it, node, adj, vis, timer, low, bridges);
            // while returning from the dfs call
            low[node] = min(low[it], low[node]);
            // and if low[it] > timer[node], then the edge is a bridge
            if (low[it] > timer[node])
            {
                bridges.push_back({it, node});
            }
        }
        else
        {
            // the node is visited and it's not the parent
            low[node] = min(low[it], low[node]);
        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
{
    vector<int> adj[n];
    for (auto it : connections)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<int> vis(n, 0);
    vector<vector<int>> bridges;
    int timer[n];
    int low[n];
    dfs(0, -1, adj, vis, timer, low, bridges);
    return bridges;
}
