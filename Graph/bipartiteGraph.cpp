// Note : if graph has cycle and it is of odd length then graph can not be bipartite

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkForBipartite(int node, vector<int> adj[], vector<int> &color, vector<bool> &vis, int V)
    {
        // this node is the source node to whom we give a random color - 0
        color[node] = 0;
        // mark it visited
        vis[node] = true;
        queue<int> q;
        // pushing source node to queue
        q.push(node);
        while (!q.empty())
        {
            // taking top element from queue
            int topEle = q.front();
            q.pop();
            // processing neighbour of nodes
            for (auto it : adj[topEle])
            {
                // if color is -1 it means this node is node processed
                if (color[it] == -1)
                {
                    // giving color opposite to adjacent node
                    color[it] = !color[topEle];
                    // mark it visited
                    vis[it] = true;
                    // pushing the adjacent node to queue
                    q.push(it);
                }
                // if the color of adjacent node is similar to current node return false 
                else if (color[it] == color[topEle])
                    return false;
            }
        }
        return true;
    }

    bool isBipartite(int V, vector<int> adj[])
    {
        vector<int> color(V, -1);
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (checkForBipartite(i, adj, color, vis, V) == false)
                    return false;
            }
        }
        return true;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isBipartite(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}


// using dfs

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool checkForBipartite(int node, vector<int> adj[], vector<int> &color, vector<bool> &vis, int V)
    {
        color[node] = 0;
        vis[node] = true;
        stack<int> st;
        st.push(node);
        while (!st.empty())
        {
            int topEle = st.top();
            st.pop();

            for (auto it : adj[topEle])
            {
                int currNode = it;
                if (color[currNode] == -1 && !vis[it])
                {
                    color[currNode] = !color[topEle];
                    st.push(currNode);
                    vis[it] = true;
                }
                else if (color[currNode] == color[topEle])
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(int V, vector<int> adj[])
    {
        vector<int> color(V, -1);
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (checkForBipartite(i, adj, color, vis, V) == false)
                    return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isBipartite(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends