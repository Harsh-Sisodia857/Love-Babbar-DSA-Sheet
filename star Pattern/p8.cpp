//      *
//     * *
//    *   *
//   *     *
//  *       *
// *         *
// *         *
//  *       *
//   *     *
//    *   *
//     * *
//      *

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m = 0;
    for (int i = 1; i <= 12; i++)
    {
        if(i != 7)
            i <= 6 ? m++ : m--;
        for (int j = 1; j <= 11; j++)
        {
            if (j == 7 - m || j == 5 + m)
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