//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    void swap(int *a, int *b)
    {
        *a = *a + *b;
        *b = *a - *b;
        *a = *a - *b;
    }
    // Function to find transpose of a matrix.
    void transpose(vector<vector<int>> &matrix, int n)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < i; j++)
            {
                swap(&matrix[i][j], &matrix[j][i]);
            }
        }
    }

    void rotateMatrix(vector<vector<int>> &arr, int n)
    {
        transpose(arr, n);
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                swap(&arr[i][j], &arr[n - i - 1][j]);
            }
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; i++)
        {
            vector<int> a;
            for (int j = 0; j < n; j++)
            {
                cin >> x;
                a.push_back(x);
            }
            arr.push_back(a);
        }
        Solution ob;
        ob.rotateMatrix(arr, n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << arr[i][j] << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends