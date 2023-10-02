//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = 1;
        while (!q.empty())
        {
            int frontRow = q.front().first;
            int frontCol = q.front().second;
            q.pop();
            int deltaRow[] = {-1, 0, 1, 0};
            int deltaCol[] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++)
            {
                int dummyRow = frontRow + deltaRow[i];
                int dummyCol = frontCol + deltaCol[i];
                if (dummyRow >= 0 && dummyRow < n && dummyCol >= 0 && dummyCol < m &&
                    vis[dummyRow][dummyCol] == 0 && mat[dummyRow][dummyCol] == 'O')
                {
                    vis[dummyRow][dummyCol] = 1;
                    q.push({dummyRow, dummyCol});
                }
            }
        }
    }

    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // Mark 'O's on the boundary and their connected components as safe.
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if ((i == 0 || i == n - 1 || j == 0 || j == m - 1) && mat[i][j] == 'O')
                {
                    bfs(i, j, vis, mat);
                }
            }
        }

        // Mark the remaining 'O's as 'X's.
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 'O' && vis[i][j] == 0)
                {
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];

        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends