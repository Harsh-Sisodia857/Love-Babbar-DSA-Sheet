#include <bits/stdc++.h>
using namespace std;

int kLargestElement(int arr[], int l, int r, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }
    for (int i = k; i <= r; i++)
    {
        if (pq.top() < arr[i])
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

int main()
{
    int arr[] = {-1, 85, 6, 72, 1};
    cout << kLargestElement(arr, 0, 4, 3);
    return 0;
}