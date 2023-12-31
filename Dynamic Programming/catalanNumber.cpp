//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the nth catalan number.
    int catalan(int n)
    {
        if (n == 0 || n == 1)
        {
            return 1;
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans += catalan(n - i - 1) * catalan(i);
        return ans;
    }
    int findCatalan(int n)
    {
        return catalan(n);
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
        Solution obj;
        cout << obj.findCatalan(n) << "\n";
    }
    return 0;
}
//memoization
const int mod = 1e9 + 7; // mod
long long int catalan(int n, vector<int> &dp)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = (ans + (catalan(n - i - 1, dp) *
                      catalan(i, dp)) %
                         mod) %
              mod;
    }
    return dp[n] = ans;
}
int findCatalan(int n)
{
    vector<int> dp(n + 1, -1);
    return catalan(n, dp);
}

// 