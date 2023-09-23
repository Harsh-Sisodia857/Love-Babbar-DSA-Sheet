//  Problem Link : https://practice.geeksforgeeks.org/problems/number-of-provinces/1
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void bfs(int node, vector<bool> &vis, map<int, list<int>> &adjList)
    {
        queue<int> q;
        q.push(node);
        vis[node] = true;
        while (!q.empty())
        {
            int frontNode = q.front();
            q.pop();
            for (auto it : adjList[frontNode])
            {
                if (!vis[it])
                {
                    vis[it] = true;
                    q.push(it);
                }
            }
        }
    }
    int numProvinces(vector<vector<int>> adj, int V)
    {
        // creating adjacency list
        map<int, list<int>> adjList;
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (i != j && adj[i][j] == 1)
                {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        int count = 0;
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                count++;
                bfs(i, vis, adjList);
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, x;
        cin >> V;

        vector<vector<int>> adj;

        for (int i = 0; i < V; i++)
        {
            vector<int> temp;
            for (int j = 0; j < V; j++)
            {
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution ob;
        cout << ob.numProvinces(adj, V) << endl;
    }
    return 0;
}
// } Driver Code Ends