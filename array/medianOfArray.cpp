#include<bits/stdc++.h>
using namespace std;
int find_median(vector<int> v)
{
    int size = v.size();
    if (size % 2 != 0)
    {
        int med = (((0 + size) / 2)+1);
        return v[med];
    }
    else
    {
        int n1 = size / 2;
        int n2 = floor(size - 1 / 2);
        int med = v[n1] + v[n2];
        return med / 2;
    }
}

int main(int argc, char const *argv[])
{

        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n;i++)
            cin >> v[i];
        cout << find_median(v);
    return 0;
}
