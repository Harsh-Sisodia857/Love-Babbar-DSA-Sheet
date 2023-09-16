//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution
{
public:
    static bool cmp(const pair<double, Item> &a, const pair<double, Item> &b)
    {
        return a.first > b.first;
    }
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {

        vector<pair<double, Item>> v;
        for (int i = 0; i < n; i++)
        {
            double wpu = (double)arr[i].value / arr[i].weight;
            v.push_back({wpu, arr[i]});
        }
        double totalValue = 0;
        sort(v.begin(), v.end(), cmp);
        for (int i = 0; i < n; i++)
        {
            if (W < v[i].second.weight)
            {
                // i can only take fraction out of it
                totalValue += (W * v[i].first);
                W = 0;
            }
            else
            {
                // i can take whole weight
                totalValue += v[i].second.value;
                W = W - v[i].second.weight;
            }
        }
        return totalValue;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    // taking testcases
    cin >> t;
    cout << setprecision(2) << fixed;
    while (t--)
    {
        // size of array and weight
        int n, W;
        cin >> n >> W;

        Item arr[n];
        // value and weight of each item
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].value >> arr[i].weight;
        }

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends