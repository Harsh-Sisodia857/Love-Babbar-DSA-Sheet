//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find minimum time required to rot all oranges.
    int orangesRotting(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int vis[n][m];
        queue<pair<pair<int, int>, int>> q; // {{r,c},t}
        // push all the rotten oranges in the queue
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
                else
                {
                    vis[i][j] = 0;
                }
            }
        }
        int deltaRow[] = {-1, 0, +1, 0};
        int deltaCol[] = {0, 1, 0, -1};
        int mxTime = 0;
        while (!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            mxTime = max(mxTime, time);
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int newRow = row + deltaRow[i];
                int newCol = col + deltaCol[i];
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && vis[newRow][newCol] == 0 && grid[newRow][newCol] == 1)
                {
                    q.push({{newRow, newCol}, time + 1});
                    vis[newRow][newCol] = 2;
                }
            }
        }
        // checking for fresh orange in grid
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && vis[i][j] != 2)
                    return -1;
            }
        }

        return mxTime;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.orangesRotting(grid);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends