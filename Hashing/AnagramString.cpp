#include <bits/stdc++.h>
using namespace std;
int main()
{
    int num;
    cin >> num;
    while (num--)
    {
        string s, t;
        cin >> s >> t;
        unordered_map<char, int> mp;
        for (int i = 0; i < s.length(); i++)
        {
            mp[s[i]]++;
        }

        int count = 0;
        for (int i = 0; i < t.length(); i++)
        {
            if (mp.find(t[i]) == mp.end())
            {
                count++;
            }
            else
            {
                mp[t[i]]--;
                if (mp[t[i]] < 0)
                {
                    count++;
                }
            }
        }
        cout << "BEFORE : " << count << endl;
        for (auto it : mp)
        {
            if(it.second > 0)
                count += it.second;
        }

        cout << count << endl;
    }
}