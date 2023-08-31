//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for c++
class Solution
{
public:
    int findMaxLen(string s)
    {
        stack<char> characterArray;
        stack<int> problemeticIndex;
        problemeticIndex.push(-1);
        int maxLen = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                characterArray.push('(');
                problemeticIndex.push(i);
            }
            else if (s[i] == ')')
            {
                if (!characterArray.empty() && characterArray.top() == '(')
                {
                    characterArray.pop();
                    problemeticIndex.pop();
                    int ans = i - problemeticIndex.top();
                    maxLen = max(maxLen, ans);
                }
                else
                {
                    problemeticIndex.push(i);
                }
            }
        }
        return maxLen;
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
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}

// } Driver Code Ends