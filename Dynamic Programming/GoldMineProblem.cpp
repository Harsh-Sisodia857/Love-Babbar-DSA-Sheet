// recursion

#include <bits/stdc++.h>
using namespace std;

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

// Memoization



#include <bits/stdc++.h>
using namespace std;



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

// tabulation

int maxGold(int n, int m, vector<vector<int>> M)
{
    vector<vector<int>> dp(n, vector<int>(m, 0));

    // Initialize the last column of dp with the values from the matrix
    for (int i = 0; i < n; i++)
    {
        dp[i][m - 1] = M[i][m - 1];
    }

    // Iterate from the second last column to the first
    for (int col = m - 2; col >= 0; col--)
    {
        for (int row = 0; row < n; row++)
        {
            int right = M[row][col] + dp[row][col + 1];
            int diagonallyUp = (row - 1 >= 0) ? M[row][col] + dp[row - 1][col + 1] : 0;
            int diagonallyDown = (row + 1 < n) ? M[row][col] + dp[row + 1][col + 1] : 0;

            // Update the dp matrix with the maximum of the three possibilities
            dp[row][col] = max(right, max(diagonallyUp, diagonallyDown));
        }
    }

    // Find the maximum value in the first column of dp
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, dp[i][0]);
    }

    return maxi;
}