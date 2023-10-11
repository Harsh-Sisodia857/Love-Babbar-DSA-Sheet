//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    long long int kadane(vector<int> &a, int n)
    {
        long long int maxSum = INT_MIN;
        long long int currSum = 0;
        for (int i = 0; i < n; i++)
        {
            currSum += a[i];
            maxSum = max(maxSum, currSum);
            if (currSum < 0)
                currSum = 0;
        }
        return maxSum;
    }
    long long int smallestSumSubarray(vector<int> &a)
    {
        int n = a.size();
        for (int i = 0; i < n; i++)
        {
            a[i] = -a[i];
        }
        return -1 * (kadane(a, n));
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
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ob;

        int ans = ob.smallestSumSubarray(a);

        cout << ans << endl;
    }
}
// } Driver Code Ends