//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    int minNeg(vector<int> &a)
    {
        int minNegative = INT_MAX; // Initialize to positive infinity
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] < 0)
            {
                minNegative = min(minNegative, abs(a[i]));
            }
        }
        return minNegative * -1;
    }

    long long int findMaxProduct(vector<int> &a, int n)
    {
        int mod = 1000000007;
        if (n == 1)
            return a[0];
        long long countNeg = 0, countZero = 0, product = 1;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 0)
            {
                countZero++;
                continue;
            }
            if (a[i] < 0)
            {
                countNeg++;
            }
            product = (((product) % mod) * a[i]) % mod;
        }
        if (countZero == n)
            return 0;
        if (countNeg + countZero == n && countZero > 0 && countNeg == 1)
            return 0;
        if (countNeg % 2 == 0)
        {
            return product;
        }
        int minNegative = minNeg(a);
        // cout << product << endl;
        if (minNegative == 0)
            return 0; // Prevent division by zero
        return product / minNegative;
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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr, n);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends