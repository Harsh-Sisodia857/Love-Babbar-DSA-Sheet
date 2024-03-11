void dfs(int node, vector<int> adj[], vector<bool> &vis)
{
    vis[node] = true;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, adj, vis);
        }
    }
}

int findMotherVertex(int V, vector<int> adj[])
{
    vector<bool> vis(V, false);
    int motherVertex = -1;

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis);
            motherVertex = i; // Update potential mother vertex
        }
    }

    // Check if the last visited node covers all other nodes
    fill(vis.begin(), vis.end(), false);
    dfs(motherVertex, adj, vis);
    for (bool visited : vis)
    {
        if (!visited)
        {
            return -1; // No mother vertex found
        }
    }

    return motherVertex;
}
