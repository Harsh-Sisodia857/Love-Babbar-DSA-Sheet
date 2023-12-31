#include<bits/stdc++.h>
using namespace std;
int main()
  {
      int x = 10, y = 5;
      // by addition and subtraction
      x = x + y;
      y = x - y;
      x = x - y;
      cout << x << " " << y << endl;

      // by xor
      x = x ^ y;
      y = x ^ y;
      x = x ^ y;
      cout << x << " " << y << endl;

      // by multiplication and division
      if(x == 0){
          x = y;
          y = 0;
          cout << x << " " << y << endl;
      }else if(y == 0){
          y = x;
          x = 0;
      }else{
          x = x * y;
          y = x / y;
          x = x / y;
      }

      return 0;
  }