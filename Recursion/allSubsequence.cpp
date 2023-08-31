#include<bits/stdc++.h>
using namespace std;

void allSubsequence(int idx,int arr[],vector<int> &ds,int n){
    if(idx == n){
        for(auto it : ds)
            cout << it << " ";
        cout << endl;
        return;
    }
    // pick
    ds.push_back(arr[idx]);
    allSubsequence(idx + 1, arr, ds, n);
    // not pick
    ds.pop_back();
    allSubsequence(idx + 1, arr, ds, n);
}

int main(){
    int arr[] = {1, 4, 2};
    vector<int> ds;
    allSubsequence(0,arr, ds, 3);
    return 0;
  }