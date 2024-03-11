//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find out minimum steps Knight needs to reach target position.
    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int n)
    {
        int x = KnightPos[0] - 1;
        int y = KnightPos[1] - 1;
        int targetX = TargetPos[0] - 1;
        int targetY = TargetPos[1] - 1;
        queue<pair<int, pair<int, int>>> q;
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        q.push({0, {x, y}});
        vis[x][y] = true;
        while (!q.empty())
        {
            int currX = q.front().second.first;
            int currY = q.front().second.second;
            int steps = q.front().first;
            if (currX == targetX && currY == targetY)
            {
                return steps;
            }
            q.pop();
            int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
            int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};
            for (int i = 0; i < 8; i++)
            {
                int nRow = currX + dx[i];
                int nCol = currY + dy[i];
                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < n && !vis[nRow][nCol])
                {
                    q.push({steps + 1, {nRow, nCol}});
                    vis[nRow][nCol] = true;
                }
            }
        }
        return -1;
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