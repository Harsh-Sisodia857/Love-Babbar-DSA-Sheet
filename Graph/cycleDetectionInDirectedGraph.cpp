// using dfs
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool cycleUtil(int node, vector<bool> &vis, vector<bool> &visDfs, vector<int> adj[])
    {
        vis[node] = true;
        visDfs[node] = true;

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                if (cycleUtil(it, vis, visDfs, adj))
                {
                    return true;
                }
            }
            else if (visDfs[it])
            {
                return true;
            }
        }

        visDfs[node] = false;
        return false;
    }

    bool isCyclic(int V, vector<int> adj[])
    {
        // using dfs
        vector<bool> vis(V, false);
        vector<bool> visDfs(V, false);
        for (int i = 0; i < V; i++)
        {
            if (vis[i] == false)
            {
                bool isCycle = cycleUtil(i, vis, visDfs, adj);
                if (isCycle)
                    return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}


// using bfs and kahn's algo

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        vector<int> indegree(V, 0);
        queue<int> q;
        // finding indegree of node
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
                indegree[it]++;
        }

        // pushing the node into queue whose indegree is zero
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
        }
        int count = 0;
        // do bfs
        while (!q.empty())
        {
            int topElement = q.front();
            q.pop();

            count++;
            for (auto neighbour : adj[topElement])
            {
                indegree[neighbour]--;
                if (indegree[neighbour] == 0)
                    q.push(neighbour);
            }
        }
        // count equal to V means valid topological sort it means no cycle is present in graph
        if (count == V)
            return false;
        return true;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends