#include<bits/stdc++.h>
using namespace std;
int main()
  {
      int arr[] = {3, 14, 5, 1, 2, 24};
      priority_queue<int, vector<int>, greater<int>> pq;
      int k;
      cout << "K should be less than " << 6 << endl;
      cin >> k;
      for (int i = 0; i < 6; i++){
          pq.push(arr[i]);
      }
      int count = 0,ans = -1;
      while(!pq.empty() || count < k){
          int top = pq.top();
          pq.pop();
          count++;
          if(count == k)
              ans = top;
      }
      cout << ans << " ";
      return 0;
  }