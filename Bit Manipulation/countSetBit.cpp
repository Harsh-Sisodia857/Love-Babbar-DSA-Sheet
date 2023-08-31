//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int getBit(int N, int pos)
    {
        return (N & (1 << pos)) != 0;
    }

    int setBits(int N)
    {
        int count = 0;
        for (int i = 0; i < sizeof(int) * 8; i++)
        {
            if (getBit(N, i) == 1)
                count++;
        }

        return count;
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

        Solution ob;
        int cnt = ob.setBits(N);
        cout << cnt << endl;
    }
    return 0;
}

// } Driver Code Ends