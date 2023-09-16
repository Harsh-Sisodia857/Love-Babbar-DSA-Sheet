//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> find(int arr[], int n, int x)
    {
        int low = 0;
        int high = n - 1;
        int mid;
        int startIdx = -1;
        vector<int> ans;
        // first Occurence
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (arr[mid] > x)
            {
                high = mid - 1;
            }
            else if (arr[mid] < x)
            {
                low = mid + 1;
            }
            else
            {
                startIdx = mid;
                high = mid - 1;
            }
        }
        int endIdx = -1;
        low = 0;
        high = n - 1;
        // lastOccurence
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (arr[mid] > x)
            {
                high = mid - 1;
            }
            else if (arr[mid] < x)
            {
                low = mid + 1;
            }
            else
            {
                endIdx = mid;
                low = mid + 1;
            }
        }
        ans.push_back(startIdx);
        ans.push_back(endIdx);
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
        int n, x;
        cin >> n >> x;
        int arr[n], i;
        for (i = 0; i < n; i++)
            cin >> arr[i];
        vector<int> ans;
        Solution ob;
        ans = ob.find(arr, n, x);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}

// } Driver Code Ends