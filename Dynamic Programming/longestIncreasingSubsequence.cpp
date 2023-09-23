// recursion
int f(int idx,int prev,int arr[], int n){
    // base case
    if(idx == n){
        return 0;
    }

    // pick
    int pick = 0;
    if(arr[idx] > arr[prev])
        pick = 1 + f(idx+1,idx,arr,n);
    // not pick
    int notPick =0 + f(idx+1,prev,arr,n);
    return max(pick,notPick);
}

int longestIncreasingSubsequence(int arr[], int n)
{
    return f(0,-1,arr,n);
}

// memoization

#include <vector>
int f(int idx, int prev, int arr[], int n, vector<vector<int>> &dp)
{
    // base case
    if (idx == n)
    {
        return 0;
    }
    if (dp[idx][prev + 1] != -1)
        return dp[idx][prev + 1];

    // pick
    int pick = 0;
    if (arr[idx] > arr[prev] || prev == -1)
        pick = 1 + f(idx + 1, idx, arr, n, dp);
    // not pick
    int notPick = 0 + f(idx + 1, prev, arr, n, dp);
    return dp[idx][prev + 1] = max(pick, notPick);
}

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return f(0, -1, arr, n, dp);
}

// tabulation

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int prev = idx - 1; prev >= -1; prev--)
        {
            // pick
            int pick = 0;
            if (arr[idx] > arr[prev] || prev == -1)
                pick = 1 + dp[idx + 1][idx + 1];
            // not pick
            int notPick = 0 + dp[idx + 1][prev + 1];
            dp[idx][prev + 1] = max(pick, notPick);
        }
    }
    return dp[0][0];
}

// using binary search

#include <vector>
#include <algorithm> // for lower_bound, upper_bound and sort

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> temp;
    temp.push_back(arr[0]);
    for(int i= 1; i < n; i++){
        if(arr[i] > temp.back()){
            // arr[i] > the last element of temp array 
            temp.push_back(arr[i]);
        }else{
            int idx = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[idx] = arr[i];

        }
    }
    return temp.size();
}
