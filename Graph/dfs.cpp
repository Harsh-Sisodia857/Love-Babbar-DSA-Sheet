//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        vector<bool> vis(V, false);
        vector<int> dfs;
        stack<int> st;
        st.push(0);
        while (!st.empty())
        {
            int frontNode = st.top();
            dfs.push_back(frontNode);
            st.pop();
            vis[frontNode] = true;
            for (auto it : adj[frontNode])
            {
                if (vis[it] == false)
                {
                    st.push(it);
                    vis[it] = true;
                }
            }
        }
        return dfs;
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}

// recursive

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls)
    {
        vis[node] = 1;
        ls.push_back(node);
        // traverse all its neighbours
        for (auto it : adj[node])
        {
            // if the neighbour is not visited
            if (!vis[it])
            {
                dfs(it, adj, vis, ls);
            }
        }
    }

public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[])
    {
        int vis[V] = {0};
        int start = 0;
        // create a list to store dfs
        vector<int> ls;
        // call dfs for starting node
        dfs(start, adj, vis, ls);
        return ls;
    }
};

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector<int> &ans)
{
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    vector<int> adj[5];

    addEdge(adj, 0, 2);
    addEdge(adj, 2, 4);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);

    Solution obj;
    vector<int> ans = obj.dfsOfGraph(5, adj);
    printAns(ans);

    return 0;
}

// bipartite using dfs

#include <bits/stdc++.h>
using namespace std;

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
