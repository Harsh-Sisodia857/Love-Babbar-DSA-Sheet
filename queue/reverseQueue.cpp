//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// function Template for C++

// Function to reverse the queue.
class Solution
{
public:
    void solve(queue<int> &q)
    {
        // base case
        if (q.empty())
        {
            return;
        }
        int data = q.front();
        q.pop();
        solve(q);
        q.push(data);
    }
    queue<int> rev(queue<int> q)
    {
        solve(q);
        return q;
    }
};

//{ Driver Code Starts.
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        queue<int> q;
        int n, var;
        cin >> n;
        while (n--)
        {
            cin >> var;
            q.push(var);
        }
        Solution ob;
        queue<int> a = ob.rev(q);
        while (!a.empty())
        {
            cout << a.front() << " ";
            a.pop();
        }
        cout << endl;
    }
}
// } Driver Code Ends