//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // a knows b ---> true
    // a don't knows b ---> false
    bool knows(int a, int b, vector<vector<int>> &M)
    {
        return M[a][b];
    }
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &M, int n)
    {
        stack<int> st;
        // step 1:
        for (int i = 0; i < n; i++)
        {
            st.push(i);
        }
        // step 2:
        while (st.size() > 1)
        {
            int firstEle = st.top();
            st.pop();
            int secondEle = st.top();
            st.pop();
            if (knows(firstEle, secondEle, M))
            {
                st.push(secondEle);
            }
            else
            {
                st.push(firstEle);
            }
        }
        if (st.empty())
            return -1;
        // step 3 : one element in stack which is a potential celebrity
        // a) Row Check
        int cele = st.top();
        bool rowFlag = true;
        for (int i = 0; i < n; i++)
        {
            // ignoring diagonal
            if (i == cele)
                continue;
            if (M[cele][i] == 1)
            {
                rowFlag = false;
                break;
            }
        }
        // b) Column Check
        bool colFlag = true;
        for (int i = 0; i < n; i++)
        {
            // ignoring diagonal
            if (i == cele)
                continue;
            if (M[i][cele] == 0)
            {
                colFlag = false;
                break;
            }
        }
        if (colFlag && rowFlag)
            return cele;
        return -1;
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
        vector<vector<int>> M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M, n) << endl;
    }
}

// } Driver Code Ends