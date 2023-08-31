//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void solve(int idx, int coins[], int N, int sum, long long &Count, int currSum)
    {
        if (currSum > sum || idx >= N)
            return;
        if (currSum == sum)
        {
            Count++;
            return;
        }
        // pick

        solve(idx, coins, N, sum, Count, currSum + coins[idx]);
        // not pick
        solve(idx + 1, coins, N, sum, Count, currSum);
    }
    long long int count(int coins[], int N, int sum)
    {

        long long Count = 0;
        solve(0, coins, N, sum, Count, 0);
        return Count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++)
            cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}

// } Driver Code Ends