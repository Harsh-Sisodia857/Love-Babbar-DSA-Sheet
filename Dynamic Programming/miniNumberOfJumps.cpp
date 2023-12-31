//  recursion
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution
{
public:
    int f(int idx, int arr[], int n)
    {
        if (idx == n - 1)
            return 0;
        if (idx >= n)
            return 0;
        if (arr[idx] == 0)
            return 1e8;
        int pick = 1e8;
        for (int i = 1; i <= arr[idx]; i++)
            pick = min(pick, 1 + f(idx + i, arr, n));
        return pick;
    }
    int minJumps(int arr[], int n)
    {
        int result = f(0, arr, n);
        if (result == 1e8)
        {
            return -1; // If it's not possible to reach the end
        }
        return result;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, j;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        cout << obj.minJumps(arr, n) << endl;
    }
    return 0;
}

// Tabulation

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution
{
public:
    int f(int idx, int arr[], int n, vector<int> &dp)
    {
        if (idx == n - 1)
            return 0;
        if (idx >= n)
            return 0;
        if (arr[idx] == 0)
            return 1e8;
        if (dp[idx] != -1)
            return dp[idx];
        int pick = 1e8;
        for (int i = 1; i <= arr[idx]; i++)
            pick = min(pick, 1 + f(idx + i, arr, n, dp));
        return dp[idx] = pick;
    }
    int minJumps(int arr[], int n)
    {
        vector<int> dp(n, -1);
        int result = f(0, arr, n, dp);
        if (result == 1e8)
        {
            return -1; // If it's not possible to reach the end
        }
        return result;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, j;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        cout << obj.minJumps(arr, n) << endl;
    }
    return 0;
}

// Tabulation

int minJumps(int arr[], int n)
{
    vector<int> dp(n, INT_MAX);
    dp[n - 1] = 0;

    for (int idx = n - 2; idx >= 0; idx--)
    {
        int pick = INT_MAX;
        for (int i = 1; i <= arr[idx] && idx + i < n; i++)
        {
            pick = min(pick, 1 + f(idx + i, arr, n, dp));
        }
        dp[idx] = pick;
    }
    return dp[0] > 1e8 ? -1 : dp[0];
}