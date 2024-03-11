// Link ====>  https : // www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/little-jhool-and-the-magical-jewels/
#include <bits/stdc++.h>
               using namespace std;
int main()
{
    int num;
    cin >> num;
    while (num--)
    {
        unordered_map<char, int> mp;
        string str;
        cin >> str;
        int n = str.length();
        for (int i = 0; i < n; i++)
        {
            mp[str[i]]++;
        }
        int mini = INT_MAX;
        if (mp['u'] == 0 || mp['b'] == 0 || mp['r'] == 0 || mp['y'] == 0)
        {
            cout << 0 << endl;
            continue;
        }
        for (auto it : mp)
        {
            if ((it.first == 'r' || it.first == 'u' || it.first == 'b' || it.first == 'y'))
            {
                mini = min(mini, it.second);
            }
        }
        cout << mini << endl;
    }
}