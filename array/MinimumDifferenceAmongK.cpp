//{ Driver Code Starts
#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int minDiff(int arr[], int N, int K)
    {
        sort(arr, arr + N);
        int result = INT_MAX;
        for (int i = 0; i < N - K + 1; i++)
        {
            result = min(result, arr[i + K - 1] - arr[i]);
        }
        return result;
    }
};

//{ Driver Code Starts.

int main()
{
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        Solution obj;
        cout << obj.minDiff(a, n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends