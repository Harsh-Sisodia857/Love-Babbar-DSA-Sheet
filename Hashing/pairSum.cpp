#include <bits/stdc++.h>
#define ll                                         \
    long long #define nl 
     using namespace std; 
    const int N = 1e6 + 10;                        \
    int main()                                     \
    {                                              \
        int n, k;                                  \
        cin >> n >> k;                             \
        int a[n];                                  \
        for (int i = 0; i < n; ++i)                \
        {                                          \
            cin >> a[i];                           \
        }                                          \
        unordered_map<int, int> m;                 \
        for (int i = 0; i < n; ++i)                \
        {                                          \
            if (m[k - a[i]])                       \
            {                                      \
                cout << "YES" << nl;               \
                return 0;                          \
            }                                      \
            m[a[i]] = 1;                           \
        }                                          \
        cout << "NO" << nl;                        \
        return 0;                                  \
    }
