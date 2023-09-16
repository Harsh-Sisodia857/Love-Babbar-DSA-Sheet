// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    // Function to calculate minimum days required to buy enough food.
    int minimumDays(int S, int N, int M)
    {
        // Calculate the number of Sundays in the given days.
        int sundays = S / 7;

        // Calculate the number of buying days by subtracting Sundays.
        int buyingDays = S - sundays;

        // Calculate the total food required.
        int foodRequired = S * M;
        int ans;

        // Check if the total food required is not completely divisible by N.
        if (foodRequired % N != 0)
        {
            ans = (foodRequired / N) + 1; // Add 1 day to cover the remaining food.
        }
        else
        {
            ans = foodRequired / N; // No need to add extra days.
        }

        // If the required days are more than the available buying days, return -1.
        if (ans > buyingDays)
            return -1;
        else
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
        int S, N, M;
        cin >> S >> N >> M;

        Solution ob;
        cout << ob.minimumDays(S, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends


// second solution

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int minimumDays(int S, int N, int M)
    {
        if (N < M)
            return -1;
        int noOfSunday = S / 7;
        int openDays = S - noOfSunday;
        if (openDays * N < M * S)
            return -1;
        return ceil(1.0 * (S * M) / N);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int S, N, M;
        cin >> S >> N >> M;

        Solution ob;
        cout << ob.minimumDays(S, N, M) << endl;
    }
    return 0;
}
// } Driver Code Ends