// If n is even, it can be written as :
// n = 2 *x 
// n2 = (2 * x)2 = 4 * x2 
// If n is odd, it can be written as :
// n = 2 *x + 1
// n2 = (2 * x + 1)2 = 4 * x2 + 4 * x + 1

#include<bits/stdc++.h>
using namespace std;

int square(int n){
    if(n == 0)
        return 0;
    if(n < 0)
        n = -n;
    int x = (n >> 1); // floor(n/2)
    // if n is odd
    if (n & 1)
    {
        return (square(x) << 2) + (x << 2) + 1;
    }
    // if n is even
    else
    {
        return (square(x) << 2);
    }
}

// calculating square of a number
int main(){
    int n;
    cin >> n;
    cout <<"Square of "<<n<< " : "<< square(n);

    return 0;
  }