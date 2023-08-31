#include<bits/stdc++.h>
using namespace std;

bool subsetSum(int idx, vector<int> &arr, int sum, int n, int currSum)
{
    if (idx == n && currSum != sum)
    {
        return false;
    }
    if (currSum > sum)
        return false;
    if (currSum == sum)
        return true;
    // pick
    currSum += arr[idx];
    if (subsetSum(idx + 1, arr, sum, n, currSum))
        return true;
    // not pick
    currSum -= arr[idx];
    if (subsetSum(idx + 1, arr, sum, n, currSum))
        return true;
    return false;
}
bool isSubsetSum(vector<int> arr, int sum)
{
    int n = arr.size();
    if (subsetSum(0, arr, sum, n, 0))
        return true;
    return false;
}
int main(){
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    cout << isSubsetSum(arr, 9) << " ";
    return 0;
  }