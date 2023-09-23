//{ Problem Link : https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void dfs(int row, int col, vector<vector<bool>> &vis, vector<vector<char>> &grid)
    {
        stack<pair<int, int>> st;
        int n = grid.size();
        int m = grid[0].size();
        st.push({row, col});
        vis[row][col] = true;
        while (!st.empty())
        {
            int frontNodeRow = st.top().first;
            int frontNodeCol = st.top().second;
            st.pop();

            // visiting neighbour which is in 8 direction in the 2D Matrix
            for (int deltaRow = -1; deltaRow < 2; deltaRow++)
            {
                for (int deltaCol = -1; deltaCol < 2; deltaCol++)
                {
                    int nRow = frontNodeRow + deltaRow;
                    int nCol = frontNodeCol + deltaCol;
                    if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                        !vis[nRow][nCol] && grid[nRow][nCol] == '1')
                    {
                        vis[nRow][nCol] = true;
                        st.push({nRow, nCol});
                    }
                }
            }
        }
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();    // no. of rows
        int m = grid[0].size(); // no. of col

        // creating vis matrix
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == '1')
                {
                    count++;
                    dfs(i, j, vis, grid);
                }
            }
        }
        return count;
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
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends