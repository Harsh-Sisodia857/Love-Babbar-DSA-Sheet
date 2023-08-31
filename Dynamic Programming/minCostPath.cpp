#include<bits/stdc++.h>
using namespace std;

#define R 3
#define C 3

// recursive solution

// int minCost(int cost[R][C],int row,int col){
//     if(row > 2 || col > 2)
//         return INT_MAX;
//     if(row == 2 && col == 2 ){
//         return cost[row][col];
//     }
//     return cost[row][col] + min(minCost(cost, row + 1, col),
//                                 min(minCost(cost, row, col + 1),
//                                     minCost(cost, row + 1, col + 1)));
// }

// int main()
// {
//     int cost[R][C] = {{1, 2, 3}, {4, 8, 2}, {1, 5, 3}};
//     cout << minCost(cost, 0, 0) << endl;
//     return 0;
// }

// Memoization

// int minCost(int cost[R][C], int row, int col, int dp[R+1][C+1])
// {
//     if (row >= R || col >= C)
//         return INT_MAX;
//     if (row == R - 1 && col == C - 1)
//     {
//         return cost[row][col];
//     }

//     int ans1, ans2, ans3;

//     if (dp[row + 1][col] == INT16_MAX)
//     {
//         ans1 = minCost(cost, row + 1, col,dp);
//         dp[row+1][col] = ans1;
//     }
//     else
//     {
//         ans1 = dp[row+1][col];
//     }

//     if (dp[row][col + 1] == INT16_MAX)
//     {
//         ans2 = minCost(cost, row, col + 1,dp);
//         dp[row][col+1] = ans2;
//     }
//     else
//     {
//         ans2 = dp[row][col+1];
//     }

//     if (dp[row + 1][col + 1] == INT16_MAX)
//     {
//         ans3 = minCost(cost, row + 1, col + 1,dp);
//         dp[row+1][col+1] = ans3;
//     }
//     else
//     {
//         ans3 = dp[row+1][col+1];
//     }

//     int myAns =cost[row][col] + min(ans1, min(ans2, ans3));
//     return myAns;
// }

// int main()
// {
//     int cost[R][C] = {{1, 2, 3}, {4, 8, 2}, {1, 5, 3}};
//     int dp[R+1][C+1];
//     for (int i = 0; i <= R; i++){
//         for (int j = 0; j <= C; j++)
//             dp[i][j] = INT16_MAX;
//     }
//         cout << minCost(cost, 0, 0, dp) << endl;
//     return 0;
// }

// iterative

int minCost(int cost[R][C], int row, int col)
{
    if (row >= R || col >= C)
        return INT_MAX;
    if (row == R - 1 && col == C - 1)
    {
        return cost[row][col];
    }
    int dp[R + 1][C + 1];
    for (int i = 0; i <= R; i++)
    {
        for (int j = 0; j <= C; j++)
            dp[i][j] = INT16_MAX;
    }
    int ans1, ans2, ans3;

    for(int r = 2; r >= 0; r--){
        for (int c = 2; c >= 0; c--){
            if(r == R-1 && c == C-1)
                dp[r][c] = cost[r][c];
            else
                dp[r][c] = cost[r][c] + min(dp[r][c + 1], min(dp[r + 1][c], dp[r + 1][c + 1]));
        }
    }

    return dp[0][0];
    }

int main()
{
    int cost[R][C] = {{1, 2, 3}, {4, 8, 2}, {1, 5, 3}};
    cout << "  " << minCost(cost, 0, 0);
    return 0;
}