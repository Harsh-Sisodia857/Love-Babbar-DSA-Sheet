//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int maxEqualSum(int N1, int N2, int N3, vector<int> &S1, vector<int> &S2, vector<int> &S3)
    {
        // scroll below to know about accumulate stl
        int sum1 = accumulate(S1.begin(), S1.end(), 0);
        int sum2 = accumulate(S2.begin(), S2.end(), 0);
        int sum3 = accumulate(S3.begin(), S3.end(), 0);

        int top1 = 0, top2 = 0, top3 = 0;

        while (top1 < N1 && top2 < N2 && top3 < N3)
        {
            if (sum1 == sum2 && sum2 == sum3)
                return sum1;
            if (sum1 >= sum2 && sum1 >= sum3)
            {
                sum1 -= S1[top1++];
            }
            else if (sum2 >= sum1 && sum2 >= sum3)
            {
                sum2 -= S2[top2++];
            }
            else if (sum3 >= sum1 && sum3 >= sum2)
            {
                sum3 -= S3[top3++];
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        vector<int> s1(n1), s2(n2), s3(n3);
        for (int i = 0; i < n1; i++)
        {
            cin >> s1[i];
        }
        for (int i = 0; i < n2; i++)
        {
            cin >> s2[i];
        }
        for (int i = 0; i < n3; i++)
        {
            cin >> s3[i];
        }
        Solution ob;
        int ans = ob.maxEqualSum(n1, n2, n3, s1, s2, s3);
        cout << ans << endl;
    }

    return 0;
}
// } Driver Code Ends

The accumulate function is a part of the C++ Standard Template Library (STL) and is defined in the <numeric> header. It is used for performing a specific operation (usually addition) on all the elements in a range of values, such as an array, vector, or any sequence that can be iterated over. Here's how it works and how it is used:

#include <iostream>
#include <numeric> // Include the numeric header

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Calculate the sum of elements in the array using accumulate
    int sum = std::accumulate(arr, arr + n, 0);

    std::cout << "Sum of elements: " << sum << std::endl;

    return 0;
}
In this example:

We include the <numeric> header to use the accumulate function.

We define an integer array arr with some values.

We calculate the number of elements in the array n.

We use std::accumulate to calculate the sum of all elements in the array. The function takes three arguments:

The first argument is the beginning of the range (in this case, arr).
The second argument is the end of the range (in this case, arr + n to include all elements).
The third argument is the initial value for the sum (in this case, 0).
The result is stored in the variable sum, which will contain the sum of all elements in the array.

The accumulate function can be customized to perform other operations besides addition by providing a custom binary function as the fourth argument. For simple summation, like in the example above, the default addition operator (+) is used.

It's a convenient and efficient way to compute the sum (or other accumulative operations) of elements in a container or array without having to write a loop explicitly.
Time complexity = 0(n)