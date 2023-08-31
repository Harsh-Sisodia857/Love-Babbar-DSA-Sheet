#include<bits/stdc++.h>
using namespace std;

void sort012(int arr[], int n)
{
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }
    for (auto i : m)
    {
        for (int j = 0; j < i.second; j++) 
        {
            cout << i.first << " ";
        }
    }
}

int main()
{
    int arr[] = {1, 2, 1, 2, 0, 1, 0};
    sort012(arr, 7);
    
        return 0;
}