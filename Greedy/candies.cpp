//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        sort(candies, candies + N);
        int i = 0, j = N - 1;
        vector<int> ans;
        int minCost = 0;
        while (i <= j)
        {
            minCost += candies[i];
            i++;
            j = j - K;
        }
        i = N - 1;
        j = 0;
        int maxCost = 0;
        while (j <= i)
        {
            maxCost += candies[i];
            i--;
            j = j + K;
        }
        ans.push_back(minCost);
        ans.push_back(maxCost);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends