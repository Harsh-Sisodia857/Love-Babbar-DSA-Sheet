// bellman ford can : 1 )detect negative weight cycle in the graph
//                    2) It also give shortest path in case of negative weight
// 1)
vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges)
{
    vector<int> dist(n + 1, 1e8);
    dist[src] = 0;

    // check for (n - 1) times
    for (int node = 1; node < n; node++)
    {
        // traverse all edges
        for (int i = 0; i < m; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            if ((dist[u] + w) < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }

    return dist;
}

// 2)

vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges)
{
    vector<int> dist(n + 1, 1e8);
    dist[src] = 0;

    // check for (n - 1) times
    for (int node = 1; node < n; node++)
    {
        // traverse all edges
        for (int i = 0; i < m; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            if ((dist[u] + w) < dist[v])
            {
                dist[v] = dist[u] + w;
            }
        }
    }
    // Additional loop to check for negative weight cycles
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        // agar abhi bhi change ki possibitlity bachi hai mtlb negative cycle hai. Minimum distance from src to every other vertex n-1 times iterate krte time hi mil jana chaiye tha.
        if (dist[u] != INT_MAX && (dist[u] + w) < dist[v])
        {
            // Negative weight cycle detected
            return vector<int>(); // Return an empty vector to indicate the presence of a cycle
        }
    }
}