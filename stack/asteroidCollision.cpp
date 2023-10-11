//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids)
    {
        stack<int> st;
        vector<int> ans;

        for (int i = 0; i < asteroids.size(); i++)
        {
            // pushing the asteroid having positive value
            if (st.empty() || asteroids[i] > 0)
            {
                st.push(asteroids[i]);
            }
            else
            {
                while (!st.empty() && st.top() > 0 && st.top() < abs(asteroids[i]))
                {
                    st.pop();
                }
                if (st.empty() || st.top() < 0)
                {
                    st.push(asteroids[i]);
                }
                else if (st.top() == abs(asteroids[i]))
                {
                    st.pop();
                }
            }
        }

        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());
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
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++)
            cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans)
            cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends