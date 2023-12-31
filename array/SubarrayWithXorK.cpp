#include <bits/stdc++.h>
int subarraysWithSumK(vector < int > a, int b) {
    int n = a.size();
    int count = 0;
    unordered_map<int,int> m;
    m[0] = 1;
    int xorSum = 0;
    for(int i = 0; i < n; i++){
        xorSum = xorSum ^ a[i];
        int temp = xorSum ^ b;
        if(m.find(temp) != m.end()){
            count += m[temp];
        }else{
            m[temp]++;
        }
    }
    return count;
}