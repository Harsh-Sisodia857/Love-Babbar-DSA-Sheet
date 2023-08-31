//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<int> rearrangeQueue(queue<int> &q)
    {
        vector<int> ans;
        queue<int> tempQ;
        int n = q.size() / 2;
        while (n)
        {
            int data = q.front();
            q.pop();
            tempQ.push(data);
            n--;
        }
        while (!tempQ.empty())
        {
            int data1 = tempQ.front();
            tempQ.pop();
            ans.push_back(data1);
            int data2 = q.front();
            q.pop();
            ans.push_back(data2);
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
        int n;
        cin >> n;

        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        vector<int> ans = ob.rearrangeQueue(q);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends