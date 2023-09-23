//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void dfs(int row, int col, vector<vector<int>> &image,
             vector<vector<int>> &ans, int initialColor, int newColor)
    {
        ans[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();
        int deltaRow[] = {-1, 0, +1, 0};
        int deltaCol[] = {0, +1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int nRow = row + deltaRow[i];
            int nCol = col + deltaCol[i];
            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                image[nRow][nCol] == initialColor && ans[nRow][nCol] != newColor)
            {
                dfs(nRow, nCol, image, ans, initialColor, newColor);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        vector<vector<int>> ans = image;
        int n = image.size();
        int m = image[0].size();
        int initialColor = image[sr][sc];
        dfs(sr, sc, image, ans, initialColor, newColor);
        return ans;
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
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans)
        {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends