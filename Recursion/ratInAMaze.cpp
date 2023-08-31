//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    bool isValidPath(int row, int col, vector<vector<int>> &m, vector<vector<int>> &vis, int n)
    {
        if (row >= 0 && row < n && col >= 0 && col < n && m[row][col] == 1 && vis[row][col] == 0)
            return true;
        return false;
    }
    void ratPath(int row, int col, string s, vector<vector<int>> &m, int n,
                 vector<vector<int>> &vis, vector<string> &ans)
    {
        if (row == n - 1 && col == n - 1)
        {
            ans.push_back(s);
            return;
        }

        // D L R U
        // Down
        if (isValidPath(row + 1, col, m, vis, n))
        {
            vis[row][col] = 1;
            ratPath(row + 1, col, s + 'D', m, n, vis, ans);
            vis[row][col] = 0;
        }
        // Left
        if (isValidPath(row, col - 1, m, vis, n))
        {
            vis[row][col] = 1;
            ratPath(row, col - 1, s + 'L', m, n, vis, ans);
            vis[row][col] = 0;
        }
        // Right
        if (isValidPath(row, col + 1, m, vis, n))
        {
            vis[row][col] = 1;
            ratPath(row, col + 1, s + 'R', m, n, vis, ans);
            vis[row][col] = 0;
        }
        // UP
        if (isValidPath(row - 1, col, m, vis, n))
        {
            vis[row][col] = 1;
            ratPath(row - 1, col, s + 'U', m, n, vis, ans);
            vis[row][col] = 0;
        }
    }

    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<vector<int>> vis(n, vector<int>(n, 0));
        vector<string> ans;
        string s = "";
        if (m[0][0] == 1)
            ratPath(0, 0, s, m, n, vis, ans);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends