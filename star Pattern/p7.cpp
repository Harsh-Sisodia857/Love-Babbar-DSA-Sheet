//     *
//    ***
//   *****
//  *******
// *********
// *********
//  *******
//   *****
//    ***
//     *

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m = 0;
    for (int i = 1; i <= 10; i++)
    {
        if(i != 6)
            i <= 5 ? m++ : m--;
        for (int j = 1; j <= 9; j++)
        {
            if (j <= 4 + m && j >= 6 - m)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}