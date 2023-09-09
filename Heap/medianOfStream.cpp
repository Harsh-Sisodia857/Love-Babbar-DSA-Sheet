//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    priority_queue<int> maxpq;                            // maxHeap
    priority_queue<int, vector<int>, greater<int>> minpq; // minHeap

    // Function to insert heap.
    void insertHeap(int &num)
    {
        if (maxpq.empty() || maxpq.top() > num)
        {
            maxpq.push(num);
        }
        else
        {
            minpq.push(num);
        }
        balanceHeaps();
    }

    // Function to balance heaps.
    void balanceHeaps()
    {
        if (maxpq.size() > minpq.size() + 1)
        {
            minpq.push(maxpq.top());
            maxpq.pop();
        }
        else if (minpq.size() > maxpq.size() + 1)
        {
            maxpq.push(minpq.top());
            minpq.pop();
        }
    }

    // Function to return Median.
    double getMedian()
    {
        if (maxpq.size() == minpq.size())
        {
            return (maxpq.top() + minpq.top()) / 2.0;
        }
        else
        {
            if (maxpq.size() > minpq.size())
            {
                return maxpq.top();
            }
            else
            {
                return minpq.top();
            }
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int n, x;
    int t;
    cin >> t;
    while (t--)
    {
        Solution ob;
        cin >> n;
        for (int i = 1; i <= n; ++i)
        {
            cin >> x;
            ob.insertHeap(x);
            cout << floor(ob.getMedian()) << endl;
        }
    }
    return 0;
}
// } Driver Code Ends