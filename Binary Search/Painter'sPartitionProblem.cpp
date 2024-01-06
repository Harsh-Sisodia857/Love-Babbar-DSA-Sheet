#include <bits/stdc++.h>

bool isPossible(vector<int> &boards, int val, int k)
{
    int painterRequired = 1;
    int currUnit = 0;
    for (int i = 0; i < boards.size(); i++)
    {
        if (currUnit + boards[i] <= val)
        {
            currUnit += boards[i];
        }
        else
        {
            painterRequired++;
            currUnit = boards[i];
        }
    }
    // cout<<"possibility : "<<painterRequired<<endl;
    if (painterRequired > k)
        return false;
    return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    int low = INT_MIN;
    int high = 0;
    for (int i = 0; i < boards.size(); i++)
    {
        low = max(low, boards[i]);
        high = high + boards[i];
    }
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        bool possibility = isPossible(boards, mid, k);
        // cout<<low<<" "<<high<<" "<<possibility<<endl;
        if (possibility)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}