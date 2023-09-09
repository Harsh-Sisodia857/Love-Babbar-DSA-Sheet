//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define N 1000

// } Driver Code Ends
// you are required to complete this function
// function should print the required range
class Solution
{
public:
    pair<int, int> findSmallestRange(int kSortedArray[][N], int n, int k)
    {
        // {element,{row,col}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for (int i = 0; i < k; i++)
        {
            pq.push({kSortedArray[i][0], {i, 0}});
            if (maxi < kSortedArray[i][0])
                maxi = kSortedArray[i][0];
        }
        int range = INT_MAX;
        pair<int, int> ans;
        while (!pq.empty())
        {
            mini = pq.top().first;
            if ((maxi - mini) < range)
            {
                range = maxi - mini;
                ans.first = mini;
                ans.second = maxi;
            }
            int nextEleIdx = pq.top().second.second;
            int nextEleRow = pq.top().second.first;
            pq.pop();
            if (nextEleIdx + 1 < N)
            {
                pq.push({kSortedArray[nextEleRow][nextEleIdx + 1], {nextEleRow, nextEleIdx + 1}});
                if (maxi < kSortedArray[nextEleRow][nextEleIdx + 1])
                    maxi = kSortedArray[nextEleRow][nextEleIdx + 1];
            }
            else
            {
                break;
            }
        }

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
        int n, k;
        cin >> n >> k;
        int arr[N][N];
        pair<int, int> rangee;
        for (int i = 0; i < k; i++)
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];
        Solution obj;
        rangee = obj.findSmallestRange(arr, n, k);
        cout << rangee.first << " " << rangee.second << "\n";
    }
    return 0;
}

// } Driver Code Ends