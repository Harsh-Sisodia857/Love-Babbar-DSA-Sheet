#include<bits/stdc++.h>
using namespace std;

void solve(int idx, int arr[], vector<int> &s1, vector<int> &s2, int &sos1, int &sos2, int &minDiff, int n)
{
        if (idx == n - 1)
        {
            int diff = abs(sos1 - sos2);
            if (diff < minDiff)
            {
                minDiff = diff;
            }
            return;
        }
        // pick
        s1.push_back(arr[idx]);
        sos1 += arr[idx];
        solve(idx + 1, arr, s1, s2, sos1, sos2, minDiff, n);
        // not pick
        s1.pop_back();
        sos1 -= arr[idx];
        sos2 += arr[idx];
        solve(idx + 1, arr, s1, s2, sos1, sos2, minDiff, n);
    }

    void tugOfWar(int arr[], int n)
    {
        vector<int> s1;
        vector<int> s2;
        int sos1 = 0, sos2 = 0, minDiff = INT_MAX;
        solve(0, arr, s1, s2, sos1, sos2, minDiff, n);
        cout << "MIN DIFFERENCE : " << minDiff << endl;
        cout << "Subset 1: ";
        for (int val : s1)
        {
            cout << val << " ";
        }
        cout << endl
             << "Subset 2: ";
        for (int val : s2)
        {
            cout << val << " ";
        }
        cout << endl;
    }

    int main()
    {
        int arr[] = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
        int n = sizeof(arr) / sizeof(arr[0]);
        tugOfWar(arr, n);
        return 0;
    }