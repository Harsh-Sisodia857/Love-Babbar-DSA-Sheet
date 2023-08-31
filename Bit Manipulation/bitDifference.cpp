//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // Function to find number of bits needed to be flipped to convert A to B
    int getBit(int n, int pos)
    {
        return ((n & (1 << pos)) != 0);
    }
    int countBitsFlip(int a, int b)
    {

        int xorSum = a ^ b;
        int count = 0;
        while (xorSum)
        {
            xorSum &= (xorSum - 1);
            count++;
        }
        return count;
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;   // input the testcases
    while (t--) // while testcases exist
    {
        int a, b;
        cin >> a >> b; // input a and b

        Solution ob;
        cout << ob.countBitsFlip(a, b) << endl;
    }
    return 0;
}
// } Driver Code Ends