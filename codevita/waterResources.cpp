#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> A(n);
    vector<int> B(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> A[i];
    }

    for (int i = 0; i < n; ++i)
    {
        cin >> B[i];
    }

    double max_width = 0.0;
    int max_valley = -1;

    for (int i = 0; i < n - 2; ++i)
    {
        double width = fabs(A[i + 1] - A[i]);
        if (width > max_width)
        {
            max_width = width;
            max_valley = i + 2; // Valley index is 1-based
        }
    }

    cout << max_valley << endl;

    return 0;
}
