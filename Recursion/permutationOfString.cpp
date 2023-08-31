//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void solve(int idx, string S, int n, set<string> &ans, string res)
    {
        if (idx == n)
        {
            res = S;
            cout << "RES : " << res << endl;
            ans.insert(res);
            return;
        }

        for (int i = n - 1; i >= 0; i--)
        {
            swap(S[i], S[idx]);
            solve(idx + 1, S, n, ans, res);
            swap(S[i], S[idx]);
        }
    }

    vector<string> find_permutation(string S)
    {
        int n = S.size();
        set<string> ans;
        solve(0, S, n, ans, "");
        vector<string> final(ans.begin(), ans.end());
        return final;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.find_permutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends