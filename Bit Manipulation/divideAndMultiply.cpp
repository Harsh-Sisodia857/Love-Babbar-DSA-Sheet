// C++ implementation to Divide two
// integers without using multiplication,
// division and mod operator
#include <bits/stdc++.h>
using namespace std;

// Function to divide a by b and
// return floor value it
long long divide(long long dividend, long long divisor)
{

    // Calculate sign of divisor i.e.,
    // sign will be negative only if
    // either one of them is negative
    // otherwise it will be positive
    int sign = ((dividend < 0) ^
                (divisor < 0))
                   ? -1
                   : 1;

    // remove sign of operands
    dividend = abs(dividend);
    divisor = abs(divisor);

    // Initialize the quotient
    long long quotient = 0, temp = 0;

    // test down from the highest bit and
    // accumulate the tentative value for
    // valid bit
    for (int i = 31; i >= 0; --i)
    {

        if (temp + (divisor << i) <= dividend)
        {
            cout << " (divisor << i) : " <<  (divisor << i)<<endl;
            temp += divisor << i;
            cout << " quotient |= 1LL << i : " <<  1LL << i;
            
            quotient |= 1LL << i;
        }
    }
    // if the sign value computed earlier is -1 then negate the value of quotient
    if (sign == -1)
        quotient = -quotient;

    return quotient;
}

// Driver code
int main()
{
    int a = -2147483648, b = -1;
    cout << divide(a, b) << "\n";

    a = 43, b = -8;
    cout << divide(a, b);

    return 0;
}
