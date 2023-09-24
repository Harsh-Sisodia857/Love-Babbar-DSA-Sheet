// recursion

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int mod = 1e7;
    int f(int n)
    {
        // base case
        if (n == 1 || n == 2)
            return n;
        int Single = f(n - 1);
        int pairingWithOther = (n - 1) * f(n - 2); // n - 1 calls for f(n-2)
        return (Single + pairingWithOther) % mod;
    }
    int countFriendsPairings(int n)
    {

        return f(n);
    }
};


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.countFriendsPairings(n);
        cout << endl;
    }
}

// memoization
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int mod = 1000000007;
    long long f(int n, vector<long long> &dp)
    {
        // base case
        if (n == 1 || n == 2)
            return n;
        if (dp[n] != -1)
            return dp[n];
        long long Single = f(n - 1, dp) % mod;
        long long pairingWithOther = ((n - 1) * (f(n - 2, dp) % mod)) % mod; // n - 1 calls for f(n-2)
        return dp[n] = (Single + pairingWithOther) % mod;
    }
    int countFriendsPairings(int n)
    {
        vector<long long> dp(n + 1, -1);
        return f(n, dp);
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
        Solution ob;
        cout << ob.countFriendsPairings(n);
        cout << endl;
    }
}

// tabulation

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int mod = 1000000007;

    int countFriendsPairings(int n)
    {
        vector<long long> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i < n + 1; i++)
        {
            long long Single = dp[i - 1] % mod;
            long long pairingWithOther = ((i - 1) * (dp[i - 2]) % mod) % mod; // n - 1 calls for f(n-2)
            dp[i] = (Single + pairingWithOther) % mod;
        }
        return dp[n];
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
        Solution ob;
        cout << ob.countFriendsPairings(n);
        cout << endl;
    }
}

// } Driver Code Ends
