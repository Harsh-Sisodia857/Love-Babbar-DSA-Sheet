//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool isPossible(int node, bool graph[101][101], int col, vector<int> &color, int m, int n)
    {
        // any color valid for first node
        if (node == 0)
            return true;
        // traversing to each node
        for (int i = 0; i < n; i++)
        {
            if (i != node && graph[i][node] == 1 && color[i] == col)
                return false;
        }
        return true;
    }

    bool isValidColoring(int node, bool graph[101][101], vector<int> &color, int m, int n)
    {
        if (node == n)
            return true;
        if (n <= m)
            return true;
        // trying for each color
        for (int i = 1; i <= m; i++)
        {
            if (color[node] == 0)
            {
                if (isPossible(node, graph, i, color, m, n))
                {
                    color[node] = i;
                    if (isValidColoring(node + 1, graph, color, m, n))
                        return true;
                    color[node] = 0;
                }
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n)
    {
        vector<int> color(n, 0);
        return isValidColoring(0, graph, color, m, n);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++)
        {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++)
        {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends