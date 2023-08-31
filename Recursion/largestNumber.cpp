//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find the largest number after k swaps.
    void solve(int idx, string &ans, string str, int k, int n)
    {
        // base case
        if (idx == n || k == 0)
        {
            ans = max(ans, str);
            return;
        }
        // No swap
        solve(idx + 1, ans, str, k, n);
        // Swap
        for (int i = idx + 1; i < n; i++)
        {
            if (str[idx] < str[i])
            {
                swap(str[idx], str[i]);
                solve(idx + 1, ans, str, k - 1, n);
                swap(str[idx], str[i]);
            }
        }
    }
    string findMaximumNum(string str, int k)
    {
        string ans = "";
        int n = str.size();
        solve(0, ans, str, k, n);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout << ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}

// } Driver Code Ends