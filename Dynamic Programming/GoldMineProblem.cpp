// recursion
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int f(int row, int col, int n, int m, vector<vector<int>> M)
    {
        if (col == m - 1)
        {
            return M[row][col];
        }
        int diagonallyUp = 0;
        if (row - 1 >= 0)
            diagonallyUp = M[row][col] + f(row - 1, col + 1, n, m, M);
        int diagonallyDown = 0;
        if (row + 1 < n)
            diagonallyDown = M[row][col] + f(row + 1, col + 1, n, m, M);
        int right = M[row][col] + f(row, col + 1, n, m, M);
        // cout<<max(diagonallyUp,diagonallyDown)<<endl;
        return max(diagonallyUp, max(diagonallyDown, right));
    }

    int maxGold(int n, int m, vector<vector<int>> M)
    {
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int TotalGold = f(i, 0, n, m, M);
            // cout<<TotalGold<<endl;
            maxi = max(maxi, TotalGold);
        }
        return maxi;
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
        vector<vector<int>> M(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> M[i][j];
        }

        Solution ob;
        cout << ob.maxGold(n, m, M) << "\n";
    }
    return 0;
}
// } Driver Code Ends

// Memoization


// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int f(int row, int col, int n, int m, vector<vector<int>> M, vector<vector<int>> &dp)
    {
        if (col == m - 1)
        {
            return M[row][col];
        }
        if (dp[row][col] != -1)
            return dp[row][col];
        int diagonallyUp = 0;
        if (row - 1 >= 0)
            diagonallyUp = M[row][col] + f(row - 1, col + 1, n, m, M, dp);
        int diagonallyDown = 0;
        if (row + 1 < n)
            diagonallyDown = M[row][col] + f(row + 1, col + 1, n, m, M, dp);
        int right = M[row][col] + f(row, col + 1, n, m, M, dp);

        return dp[row][col] = max(diagonallyUp, max(diagonallyDown, right));
    }

    int maxGold(int n, int m, vector<vector<int>> M)
    {
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
            int TotalGold = f(i, 0, n, m, M, dp);
            // cout<<TotalGold<<endl;
            maxi = max(maxi, TotalGold);
        }
        return maxi;
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
        vector<vector<int>> M(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> M[i][j];
        }

        Solution ob;
        cout << ob.maxGold(n, m, M) << "\n";
    }
    return 0;
}
// } Driver Code Ends

