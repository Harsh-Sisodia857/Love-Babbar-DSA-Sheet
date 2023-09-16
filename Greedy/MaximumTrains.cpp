
// CPP to design platform for maximum stoppage
#include <bits/stdc++.h>
using namespace std;

#define n 2
#define m 5

int maxStop(int arr[m][3]){
    vector <vector<pair<int, int>>> v(n+1);
    for (int i = 0; i < m; i++){
        v[arr[i][2]].push_back({arr[i][1], arr[i][0]});
    }
    for (int i = 0; i < n; i++)
        sort(v[i].begin(), v[i].end());

    int count = 0;
    for (int i = 0; i <= n; i++){
        if(v[i].size() == 0)
            continue;
        count++;
        int x = v[i][0].first;
        for (int j = 1; j < v[i].size(); j++){
            if(x < v[i][j].second){
                count++;
                x = v[i][j].first;
            }
        }
    }
    return count;
}

int main()
{
    int arr[m][3] = {1000, 1030, 1,
                     1010, 1020, 1,
                     1025, 1040, 1,
                     1130, 1145, 2,
                     1130, 1140, 2};
    cout << "Maximum Stopped Trains = "
         << maxStop(arr);
    return 0;
}