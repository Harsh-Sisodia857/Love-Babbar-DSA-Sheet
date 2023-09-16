//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int minSubset(vector<int> &Arr, int n)
    {
        long long halfSum = 0;
        for (int i = 0; i < n; i++)
        {
            halfSum += Arr[i];
        }
        sort(Arr.begin(), Arr.end(), greater<int>());
        halfSum = halfSum / 2;
        int count = 0;
        long long currSum = 0;
        for (int i = 0; i < n; i++)
        {
            currSum += Arr[i];
            count++;
            if (currSum > halfSum)
                return count;
        }
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
        vector<int> Arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> Arr[i];
        }
        Solution ob;
        cout << ob.minSubset(Arr, N) << endl;
    }
    return 0;
}
// } Driver Code Ends