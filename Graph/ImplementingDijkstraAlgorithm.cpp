// using priority queue
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // creating min heap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // distance vector
    vector<int> dist(V, INT_MAX);
    // pushing source node
    pq.push({0, S}); // {weight,node}
    dist[S] = 0;

    // simply traversing like bfs
    while (!pq.empty())
    {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        // visiting neighbour nodes
        for (auto it : adj[node])
        {
            int n = it[0];
            int w = it[1];
            if (weight + w < dist[n])
            {
                dist[n] = weight + w;
                pq.push({weight + w, n});
            }
        }
    }
    return dist;
}

// using set

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // creating min heap
    set<pair<int, int>> st;
    // distance vector
    vector<int> dist(V, INT_MAX);
    // pushing source node
    st.insert({0, S}); // {weight,node}
    dist[S] = 0;

    // simply traversing like bfs
    while (!st.empty())
    {
        // taking first element from set as elements are in ascending order and unique in set
        auto front = *(st.begin());
        int weight = front.first;
        int node = front.second;
        st.erase(front);
        // visiting neighbour nodes
        for (auto it : adj[node])
        {
            int n = it[0];
            int w = it[1];
            if (weight + w < dist[n])
            {
                dist[n] = weight + w;
                st.insert({weight + w, n});
            }
        }
    }
    return dist;
}