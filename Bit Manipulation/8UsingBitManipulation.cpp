#include<bits/stdc++.h>
using namespace std;

int main()
  {
      int n = 5;
    //   int x = 7n / 8;

    // (n << 3) --> n*2^3 (8n)
    // (n << 3) - n --> 7n
    // ((n << 3) - n) >> 3 --> 7n/8 
      cout << (((n << 3) - n) >> 3) << endl; // 35/8 --> 4

      return 0;
  }