// ABCDCBA
// ABC CBA
// AB   BA
// A     A

#include <bits/stdc++.h>
using namespace std;
int main()
{
    for (int i = 1; i <= 7; i++)
    {
        char c = 'A';
        for (int j = 1; j <= 7; j++)
        {
            if (j <= 5 - i || j >= 3 + i)
            {
                cout << c;
                j < 4 ? ++c : --c;
          
            }
            else
            {
                cout << " ";
                if (j == 4)
                    c--;
            }
        }
        cout << endl;
    }
    return 0;
}