// Time Complexity - 0(V^2) but we can optimize it by using heap for finding the minimum node from key array which reduce time complexity to 0(Vlog V)
int spanningTree(int V, vector<vector<int>> adj[])
{
    // For prim's algo we need three data structure
    // 1) mst - which keeps track of whether a node is visited in the MST.
    vector<bool> mst(V, false);
    // 2) parent - which keeps track of the parent of a particular node in the MST.
    vector<int> parent(V, -1);
    // 3) key - which helps to find the next least distance node in the current scenario.
    vector<int> key(V, INT_MAX);
    // marking source node as 0 distance
    key[0] = 0;

    // traversing all nodes
    for (int i = 0; i < V; i++)
    {
        int mini = INT_MAX;
        int u;
        // step 1 : find minimum node in key array
        for (int i = 0; i < V; i++)
        {
            // make sure it is not visited
            if (!mst[i] && key[i] < mini)
            {
                mini = key[i];
                // the selected node -- store it in u variable
                u = i;
            }
        }

        // step 2 : mark the selected node as true in mst array (vis array)
        mst[u] = true;

        // step 3 : traverse its neighbour and update the key array and parent of node
        for (auto it : adj[u])
        {
            int neighbourNode = it[0];
            int weight = it[1];
            // mst is false and existing key is greater than current weight
            if (mst[neighbourNode] == false && key[neighbourNode] > weight)
            {
                key[neighbourNode] = weight;
                parent[neighbourNode] = u;
            }
        }
    }

    // calculating total distance of spanning tree using key array
    int sum = 0;
    for (int i = 1; i < V; i++)
        sum += key[i];

    return sum;
}


// method 2 :
int spanningTree(int V, vector<vector<int>> adj[])
{
    // minimum spanning Tree Weight
    vector<bool> vis(V, false);
    vector<int> parent(V, -1);
    // {weight,{node,parent}}
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {0, -1}});
    int sum = 0;
    while (!pq.empty())
    {
        auto wt = pq.top().first;
        auto node = pq.top().second.first;
        auto parent = pq.top().second.second;
        pq.pop();
        if (vis[node])
            continue;
        vis[node] = true;
        sum += wt;
        for (auto it : adj[node])
        {
            int weight = it[1];
            int child = it[0];
            if (!vis[child])
            {
                pq.push({weight, {child, node}});
            }
        }
    }
    return sum;
}