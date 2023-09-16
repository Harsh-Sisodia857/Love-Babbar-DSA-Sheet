//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int f(int n, int arr[], int target, vector<vector<int>> &dp)
    {
        if (n == 0)
        {
            if (target != 0)
                return (arr[0] == target) ? 1 : 0;
            else
                return 1;
            return 0;
        }
        if (dp[n][target] != -1)
            return dp[n][target];
        // pick
        int pick = 0;
        if (target >= arr[n])
            pick = f(n - 1, arr, target - arr[n], dp);
        // not pick
        int notPick = f(n - 1, arr, target, dp);
        return dp[n][target] = (pick || notPick);
    }
    int equalPartition(int N, int arr[])
    {
        int totalSum = 0;
        for (int i = 0; i < N; i++)
            totalSum += arr[i];
        if (totalSum % 2 != 0)
            return 0;
        int halfSum = totalSum / 2;
        vector<vector<int>> dp(N, vector<int>(halfSum + 1, -1));
        return f(N - 1, arr, halfSum, dp);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        if (ob.equalPartition(N, arr))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
// } Driver Code Ends