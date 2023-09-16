// 6 5 4 3 2 1 0
// 5 4 3 2 1 0
// 4 3 2 1 0
// 3 2 1 0
// 2 1 0
// 1 0
// 0

#include <bits/stdc++.h>
using namespace std;
int main()
{
    for (int i = 1; i <= 7; i++)
    {
        int n = 7 - i;
        for (int j = 1; j <= 7; j++)
        {
            if (j <= 8 - i)
            {
                cout << n;
                n--;
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