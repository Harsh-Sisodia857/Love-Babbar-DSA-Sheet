#include <bits/stdc++.h>

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{

    map<int, vector<int>> adj;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int, bool> vis;
    unordered_map<int, int> parent;
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    parent[s] = -1;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        for (auto it : adj[front])
        {
            if (!vis[it])
            {
                q.push(it);
                vis[it] = 1;
                parent[it] = front;
            }
        }
    }

    vector<int> ans;
    ans.push_back(t);
    int current = t;
    while (current != s)
    {
        current = parent[current];
        ans.push_back(current);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
