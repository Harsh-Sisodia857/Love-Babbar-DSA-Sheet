#include <bits/stdc++.h>
using namespace std;

void printAdjacencyMatrix(vector<vector<int>> &adj,int n)
{
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << adj[i][j] << " ";
        cout << endl;
    }
}

// creating adjacency matrix
void adjacencyMatrix()
{
    // enter no. of nodes and edges
    int n, m;
    cout << "Enter no. of nodes & edges respectively : ";
    cin >> n >> m;

    // Create a vector of vectors to represent the adjacency matrix
    vector<vector<int>> adj(n+1, vector<int>(n+1, 0));

    cout << "Enter the edges : " << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    printAdjacencyMatrix(adj,n);
}

void printAdjacencyList(map<int, list<int>> &adjList, int n)
{
    for (auto it : adjList)
    {
        cout << it.first << " : ";
        for (auto j : it.second)
            cout << j << " ";
        cout << endl;
    }
}

    // creating adjacency list
void adjacencyList()
{
    // enter no. of nodes and edges
    int n, m;
    cout << "Enter no. of nodes & edges respectively : ";
    cin >> n >> m;
    map<int, list<int>> adjList;

    cout << "Enter the edges : " << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    printAdjacencyList(adjList, n);
}

int main()
{
    // adjacencyMatrix();
    adjacencyList();

    return 0;
}
