// A strongly connected component is the component of a directed graph that has a path from every vertex to every other vertex in that component.It can only be used in a directed graph.

#include<stack>
#include<unordered_map>
#include<vector>

	void
	dfs(int node, stack<int> &st, unordered_map<int, int> &vis, unordered_map<int, vector<int>> &adj){
	vis[node] = 1;
	for(auto it : adj[node]){
		if(!vis[it]){
			dfs(it, st, vis, adj);
		}
	}
	st.push(node);
}

void revDfs(int node,unordered_map<int,vector<int>> &transpose,stack<int> &st,unordered_map<int,int> &vis){
		vis[node] = 1;
		for(auto it : transpose[node]){
			if(!vis[it])
				revDfs(it, transpose, st,vis);
		}
	}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	// adj list
	unordered_map<int,vector<int>> adj;
	for(int i = 0; i < edges.size();i++){
		int u = edges[i][0];
		int v = edges[i][1];
		adj[u].push_back(v);
	}

	// topo sort
	stack<int> st;
	unordered_map<int,int> vis;
	for(int i = 0; i < v;i++){
		if(!vis[i]){
			dfs(i,st,vis,adj);
		}
	}

	// reverse edge
    unordered_map<int,vector<int>> transpose;
	for(int i = 0; i < v; i++){
		vis[i] = 0;
		for(auto neighbour : adj[i]){
			transpose[neighbour].push_back(i);
		}
	}

	// reverse dfs
	int count = 0;
	while(!st.empty()){
		int top = st.top();
		st.pop();
		if(!vis[top]){
			count++;
			revDfs(top,transpose,st,vis);
		}
	}

	return count;
}