// A strongly connected component is the component of a directed graph that has a path from every vertex to every other vertex in that component.It can only be used in a directed graph.

#include<stack>
#include<unordered_map>
#include<vector>
void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, stack<int> &st)
{
	vis[node] = 1;
	for (auto it : adj[node])
	{

		if (!vis[it])
		{
			dfs(it, vis, adj, st);
		}
	}
	st.push(node);
}

void revDfs(int node, vector<int> &vis, vector<vector<int>> &reverseAdj)
{
	vis[node] = 1;
	for (auto it : reverseAdj[node])
	{
		if (!vis[it])
			revDfs(it, vis, reverseAdj);
	}
}

int kosaraju(int V, vector<vector<int>> &adj)
{
	// topo sort
	stack<int> st;
	vector<int> vis(V, 0);
	for (int i = 0; i < V; i++)
	{
		if (!vis[i])
		{
			dfs(i, vis, adj, st);
		}
	}

	// reverse edges
	vector<vector<int>> reverseAdj(V);
	for (int i = 0; i < V; i++)
	{
		vis[i] = 0;
		for (auto it : adj[i])
		{
			reverseAdj[it].push_back(i);
		}
	}

	// dfs
	int count = 0;

	while (!st.empty())
	{
		int topEle = st.top();
		st.pop();
		if (!vis[topEle])
		{
			count++;
			revDfs(topEle, vis, reverseAdj);
		}
	}
	return count;
}