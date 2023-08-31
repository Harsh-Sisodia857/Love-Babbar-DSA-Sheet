//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0)
        {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty())
        {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}

// User function Template for C++

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k)
{

    // Ek stack banao aur usme front se 1st se kth tak ka element daal do
    stack<int> s;
    for (int i = 0; i < k; i++)
    {
        int element = q.front();
        q.pop();
        s.push(element);
    }
    // Ab stack mein se ek ek karke element nikalo aur phir se queue mein peeche se daal do
    while (!s.empty())
    {
        int element = s.top();
        s.pop();
        q.push(element);
    }
    // Ab tumhara reverse kiya hua queue peeche chala gaya hoga toh usse sahi jagah laane ke liye phle se bache element ko queue ke aage se nikal kar peeche daal do
    int t = q.size() - k;

    while (t--)
    {
        int val = q.front();
        q.pop();
        q.push(val);
    }

    return q;
}