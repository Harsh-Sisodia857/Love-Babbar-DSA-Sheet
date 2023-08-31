#include<bits/stdc++.h>
using namespace std;

void combinationSum(int idx,int candidate[],int target,vector<int> &ds,int n,int currSum){
    
    if(idx == n || currSum > target){
      return;
    }

    if (currSum == target)
    {
      for (auto it : ds)
          cout << it << " ";
      cout << endl;
      return;
    }

    // pick
    currSum += candidate[idx];
    ds.push_back(candidate[idx]);
    combinationSum(idx, candidate, target, ds, n, currSum);
    
    // not pick
    currSum -= candidate[idx];
    ds.pop_back();
    combinationSum(idx + 1, candidate, target, ds, n, currSum);
}

int main()
  {
    int candidate[] = {2, 3, 6, 7};
    int n = 4;
    int target = 7;
    vector<int> ds;
    combinationSum(0, candidate, target, ds, n, 0);
    return 0;
  }