
void dfs(int node, int &count, vector<bool> &vis, vector<vector<int>> adj)
{
    vis[node] = true;
    count++;

    // visiting neighbour nodes
    for (auto it : adj[node])
    {
        if (vis[it] == false)
        {
            dfs(it, count, vis, adj);
        }
    }
}

int journeyToMoon(int n, vector<vector<int>> astronaut)
{
    // creating adjacency list
    vector<vector<int>> adj(n);
    for (auto it : astronaut)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<bool> vis(n, false);
    vector<int> countNodes;
    int numberOfComponent = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            int count = 0;
            numberOfComponent++;
            dfs(i, count, vis, adj);
            countNodes.push_back(count);
        }
    }
    int totalCombination = (n * (n - 1)) / 2;
    int notPossibleCombination = 0;
    for (auto it : countNodes)
    {
        notPossibleCombination += ((it) * (it - 1)) / 2;
    }
    return (totalCombination - notPossibleCombination);
}