//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int getNearestPowerOf2(int n)
    {
        int count = 0;
        while ((1 << count) <= n)
        {
            count++;
        }
        return count - 1;
    }
    int countSetBits(int n)
    {
        if (n == 0)
            return 0;
        int x = getNearestPowerOf2(n);
        // x * 2^(x-1)
        int t1 = ((1 << (x - 1)) * x);
        // n - (2^x) + 1
        int t2 = n - (1 << x) + 1;
        int rest = countSetBits(n - (1 << x));
        int ans = t1 + t2 + rest;
        return ans;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin >> t;   // input testcases
    while (t--) // while testcases exist
    {
        int n;
        cin >> n; // input n
        Solution ob;
        cout << ob.countSetBits(n) << endl; // print the answer
    }
    return 0;
}

// } Driver Code Ends