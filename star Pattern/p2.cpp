// ****
// *  *
// *  *
// *  *
// ****

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 5;
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            if (j == 1 || j == 5 || i == 1 || i == 4)
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}