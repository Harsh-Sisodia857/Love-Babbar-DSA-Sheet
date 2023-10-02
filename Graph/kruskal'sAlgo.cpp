#include <algorithm>
void makeSet(vector<int> &parent, vector<int> &rank, int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findPar(vector<int> &parent, int node)
{
    if (parent[node] == node)
    {
        return node;
    }
    return parent[node] = findPar(parent, parent[node]); // path compression
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findPar(parent, u);
    v = findPar(parent, v);
    if (rank[u] < rank[v])
    {
        // chote wale ko bade ke niche laga diya
        parent[u] = v;
    }
    else if (rank[u] > rank[v])
    {
        // chote wale ko bade ke niche laga diya
        parent[v] = u;
    }
    else
    {
        parent[u] = v;
        rank[v]++;
    }
}

bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

int minimumSpanningTree(vector<vector<int>> &edges, int n)
{
    sort(edges.begin(), edges.end(), cmp);
    vector<int> rank(n);
    vector<int> parent(n);
    makeSet(parent, rank, n);
    int minWeight = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = findPar(parent, edges[i][0]);
        int v = findPar(parent, edges[i][1]);
        int w = edges[i][2];
        if (u != v)
        {
            unionSet(u, v, parent, rank);
            minWeight += w;
        }
    }
    return minWeight;
}


// practicing :

#include <algorithm>
bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

void makeSet(vector<int> &parent, vector<int> &rank, int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(int node, vector<int> &parent)
{
    if (parent[node] == node)
        return node;
    return parent[node] = findParent(parent[node], parent); // to do path compression just replace it with : return parent[node] = findParent(parent[node], parent);
}

void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
    if (rank[u] > rank[v])
    {
        parent[v] = u;
    }
    else if (rank[v] > rank[u])
    {
        parent[u] = v;
    }
    else
    {
        parent[u] = v;
        rank[v]++;
    }
}

int minimumSpanningTree(vector<vector<int>> &edges, int n)
{
    sort(edges.begin(), edges.end(), cmp);
    // parent array
    vector<int> parent(n);
    // rank array
    vector<int> rank(n);
    // initializing parent and rank
    makeSet(parent, rank, n);

    int minWeight = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        int parentOfU = findParent(u, parent);
        int parentOfV = findParent(v, parent);
        // if parent of u and v are not same then merge them
        if (parentOfU != parentOfV)
        {
            unionSet(parentOfU, parentOfV, parent, rank);
            minWeight += w;
        }
        // else ignore it
    }
    return minWeight;
}