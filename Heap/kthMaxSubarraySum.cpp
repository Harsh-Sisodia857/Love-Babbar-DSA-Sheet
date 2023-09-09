// C++ program to find the K-th largest sum
// of subarray
#include <bits/stdc++.h>
using namespace std;

// Function to calculate Kth largest element
// in contiguous subarray sum
int kthLargestSum(int arr[], int N, int k)
{
    // calculating prefix array
    int sum[N + 1];
    sum[0] = 0;
    sum[1] = arr[1];
    for (int i = 2; i <= N; i++){
        sum[i] = sum[i - 1] + arr[i-1];
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= N; i++){
        for (int j = i; j <= N;j++){
            int x = sum[i] - sum[j - 1];
            if(pq.size() < k)
                pq.push(x);
            else{
                if(pq.top() < x){
                    pq.pop();
                    pq.push(x);
                }
            }
        }
    }
    return pq.top();
}

// Driver's code
int main()
{
    int a[] = {10, -10, 20, -40};
    int N = sizeof(a) / sizeof(a[0]);
    int K = 6;

    // Function call
    cout << kthLargestSum(a, N, K);
    return 0;
}
