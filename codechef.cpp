#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int chefMarble, friendMarble;
        cin >> chefMarble >> friendMarble;

        if (chefMarble % friendMarble == 0)
        {
            cout << 0 << endl;
        }
        else
        {
            int x = chefMarble, y = friendMarble;
            int f1 = 0, f2 = 0;
            int count1 = 0, count2 = 0;

            while (chefMarble > 1)
            {
                chefMarble -= 1;
                friendMarble += 1;
                count1 += 1;
                if (chefMarble % friendMarble == 0)
                {
                    f1 = 1;
                    break;
                }
            }

            while (y > 1) {
                x += 1;
                y -= 1;
                count2 += 1;
                if (x % y == 0) {
                    f2 = 1;
                    break;
                }
            }

            if (f1 == 1 && f2 == 1) {
                cout << min(count1, count2) << endl;
            } else if (f1 == 1) {
                cout << count1 << endl;
            } else {
                cout << count2 << endl;
            }
        }
    }

    return 0;
}
