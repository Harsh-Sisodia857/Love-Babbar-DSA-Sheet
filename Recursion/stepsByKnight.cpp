//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find out minimum steps Knight needs to reach target position.

    bool isValid(int row, int col, int n, vector<vector<int>> &vis)
    {
        if (row >= 0 && row < n && col >= 0 && col < n && vis[row][col] == 0)
            return true;
        return false;
    }

    void solve(int row, int col, int targetRow, int targetCol, int n,
               vector<vector<int>> &vis, int &Minsteps, int step)
    {
        if (row == targetRow && col == targetCol)
        {
            Minsteps = min(Minsteps, step);
            return;
        }
        int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
        int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};
        for (int i = 0; i < 8; i++)
        {
            if (isValid(row + dx[i], col + dy[i], n, vis))
            {
                vis[row][col] = 1;
                solve(row + dx[i], col + dy[i], targetRow, targetCol, n, vis, Minsteps, step + 1);
                // cout << Minsteps << " " << step << endl;
                vis[row][col] = 0;
            }
        }
    }
    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
    {
        int steps = INT_MAX;
        int startRow = KnightPos[0];
        int startCol = KnightPos[1];
        int targetRow = TargetPos[0];
        int targetCol = TargetPos[1];
        vector<vector<int>> vis(N, vector<int>(N, 0));
        solve(startRow, startCol, targetRow - 1, targetCol - 1, N, vis, steps, 0);
        return (steps == INT_MAX) ? -1 : steps;
        ;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        vector<int> KnightPos(2);
        vector<int> TargetPos(2);
        int N;
        cin >> N;
        cin >> KnightPos[0] >> KnightPos[1];
        cin >> TargetPos[0] >> TargetPos[1];
        Solution obj;
        int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends