#include<bits/stdc++.h>
using namespace std;

// fibonacci using Recursion + DP =  Memoization
int fib(int n,int arr[]){
    if(n == 0 || n == 1)
        return n;
    int t1;
    int t2;
    if(arr[n-1] == -1){
        t1 = fib(n - 1, arr);
        arr[n - 1] = t1;
    }else{
        t1 = arr[n-1];
    }
    if(arr[n-2] == -1){
        t2 = fib(n - 2, arr);
        arr[n - 2] = t2;
    }
    else{
        t2 = arr[n - 2];
    }
    return (t1 + t2);
}

// Recursion using iteration
int fibI(int n){
    //base case
    if (n == 0 || n == 1)
        return n;
    int arr[n + 1];
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i < n; i++)
        arr[i] = -1;
    int ans1, ans2, ans;
    if(arr[n-1] == -1){
        ans1 = fibI(n - 1);
        arr[n - 1] = ans1;
    }
    else
        ans1 = arr[n - 1];
    if(arr[n-2] == -1){
        ans2 = fibI(n - 2);
        arr[n - 2] = ans2;
    }
    else
        ans2 = arr[n - 2];
    ans = ans1 + ans2;
    return ans;
}

int main()
  {
      int n;
      cin >> n;
      int arr[n];
      for (int i = 0; i < n; i++)
          arr[i] = -1;
    //   cout << fib(n, arr);
      cout << fibI(n);
      return 0;
  }