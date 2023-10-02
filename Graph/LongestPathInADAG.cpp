int INF = 1e9;

vector<int> topologicalSort(vector<vector<pair<int, int>>> adj, stack<int> st, int src)
{
    st.push(src);
    vector<int> topoSort;
    while (!st.empty())
    {
        int topEle = st.top();
        topoSort.push_back(topEle);
        st.pop();
        for (auto it : adj[topEle])
        {
            int neighbour = it.first;
            int cost = it.second;
            st.push(neighbour);
        }
    }
    return topoSort;
}

vector<int> maximumDistance(vector<vector<int>> edges, int v, int e, int src)
{
    vector<vector<pair<int, int>>> adj(v);

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        adj[u].push_back({v, w});
    }

    // topologicalSort
    stack<int> st;
    vector<int> topoSort = topologicalSort(adj, st, src);

    // applying the same logic as Dijkstra
    vector<int> dist(v, INT_MIN);
    priority_queue<pair<int, int>> pq;
    pq.push({0, src});
    dist[src] = 0;

    while (!pq.empty())
    {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for (auto it : adj[node])
        {
            int wt = it.second;
            int adjNode = it.first;
            if (cost + wt > dist[adjNode])
            {
                dist[adjNode] = cost + wt;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}
