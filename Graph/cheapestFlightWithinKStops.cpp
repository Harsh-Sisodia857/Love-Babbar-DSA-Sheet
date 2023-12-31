int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<pair<int, int>> adj[n];
    for (auto it : flights)
    {
        adj[it[0]].push_back({it[1], it[2]});
    }
    vector<int> dist(n, 1e9);
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {src, 0}});
    dist[src] = 0;
    while (!q.empty())
    {
        auto frontEle = q.front();
        q.pop();
        int stops = frontEle.first;
        int node = frontEle.second.first;
        int cost = frontEle.second.second;
        if (stops > k)
            continue;
        // visiting neighbour of nodes
        for (auto it : adj[node])
        {
            int neighNode = it.first;
            int ct = it.second;
            if (cost + ct < dist[neighNode])
            {
                dist[neighNode] = cost + ct;
                q.push({stops + 1, {neighNode, ct + cost}});
            }
        }
    }
    if (dist[dst] == 1e9)
        return -1;
    return dist[dst];
}