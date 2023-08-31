#include <bits/stdc++.h>
using namespace std;

void allSubsequenceK(int idx, int arr[], vector<int> &ds, int n, int k,int sum,int &count)
{
    if (idx == n)
    {
        if (sum == k)
        {
            count++;
            for(auto it : ds)
                cout << it << " ";
            cout << endl;
        }
        return;
    }
    // pick
    ds.push_back(arr[idx]);
    sum += arr[idx];
    allSubsequenceK(idx + 1, arr, ds, n, k,sum,count);

    // not pick
    ds.pop_back();
    sum -= arr[idx];
    allSubsequenceK(idx + 1, arr, ds, n, k,sum,count);
}

int main()
{
    int arr[] = {3,6, 4, 5, 3};
    vector<int> ds;
    int count = 0;
    allSubsequenceK(0, arr, ds, 5, 9,0,count);
    cout << count << " ";
    return 0;
}