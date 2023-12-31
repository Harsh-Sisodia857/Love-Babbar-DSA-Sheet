// recursion
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the total number of possible unique BST. 
    int solve(int n){
        if(n <= 1)
            return 1;
        int ans = 0;
        // i ---> root node
        for(int i = 1; i <= n; i++){
            ans += solve(i-1) * solve(n - i); // solve(i-1) -->no. of left unique bst possible and solve(n - i) --> no. of right unique bst possible
        }
        return ans;
    }
    int numTrees(int N) 
    {
        return solve(N);
    }
};

//{ Driver Code Starts.
#define mod (int)(1e9+7)
int main(){
    
    //taking total testcases
    int t;
    cin>>t;
    while(t--){
        
        //taking total number of elements
        int n;
        cin>>n;
        Solution ob;
        //calling function numTrees()
        cout<<ob.numTrees(n)<<"\n";
    }
}	
// } Driver Code Ends

// memoization
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return the total number of possible unique BST.
    int solve(int n, vector<int> &dp)
    {
        if (n <= 1)
            return 1;
        if (dp[n] != -1)
            return dp[n];
        int ans = 0;
        // i ---> root node
        for (int i = 1; i <= n; i++)
        {
            ans += solve(i - 1, dp) * solve(n - i, dp); // solve(i-1) -->no. of left unique bst possible and solve(n - i) --> no. of right unique bst possible
        }
        return dp[n] = ans;
    }
    int numTrees(int N)
    {
        vector<int> dp(N + 1, -1);
        return solve(N, dp);
    }
};

//{ Driver Code Starts.
#define mod (int)(1e9 + 7)
int main()
{

    // taking total testcases
    int t;
    cin >> t;
    while (t--)
    {

        // taking total number of elements
        int n;
        cin >> n;
        Solution ob;
        // calling function numTrees()
        cout << ob.numTrees(n) << "\n";
    }
}
// } Driver Code Ends

// iterative
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int mod = 1e9 + 7;
    int solveTab(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        // no. of nodes
        for (int node = 2; node <= n; node++)
        {
            // i --> root node
            for (int i = 1; i <= node; i++)
            {
                dp[node] = (dp[node] + (dp[i - 1] * dp[node - i]) % mod) % mod;
            }
        }
        return dp[n] % mod;
    }
    int numTrees(int N)
    {
        return solveTab(N);
    }
};

//{ Driver Code Starts.
#define mod (int)(1e9 + 7)
int main()
{

    // taking total testcases
    int t;
    cin >> t;
    while (t--)
    {

        // taking total number of elements
        int n;
        cin >> n;
        Solution ob;
        // calling function numTrees()
        cout << ob.numTrees(n) << "\n";
    }
}
// } Driver Code Ends

// catalan number approach

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    const int mod = 1e9 + 7;
    long long catalan(int n, vector<int> &dp)
    {
        if (n == 0 || n == 1)
            return 1;
        if (dp[n] != -1)
            return dp[n];
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = (ans + (catalan(i, dp) * catalan(n - i - 1, dp)) % mod) % mod;
        }
        return dp[n] = ans;
    }

    long long numTrees(int N)
    {
        vector<int> dp(N + 1, -1);
        return catalan(N, dp);
    }
};

//{ Driver Code Starts.
#define mod (int)(1e9 + 7)
int main()
{

    // taking total testcases
    int t;
    cin >> t;
    while (t--)
    {

        // taking total number of elements
        int n;
        cin >> n;
        Solution ob;
        // calling function numTrees()
        cout << ob.numTrees(n) << "\n";
    }
}
// } Driver Code Ends
