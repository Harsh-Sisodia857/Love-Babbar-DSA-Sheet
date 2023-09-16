//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to reverse words in a given string.
    string reverseWords(string S)
    {
        stack<string> st;
        int l = S.length();
        string word = "";

        for (int i = 0; i < l; i++)
        {
            if (S[i] == '.')
            {
                st.push(word);
                st.push(".");
                word = "";
            }
            else
            {
                word += S[i];
            }
        }
        // pushing last word
        st.push(word);
        string ans = "";
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
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
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends