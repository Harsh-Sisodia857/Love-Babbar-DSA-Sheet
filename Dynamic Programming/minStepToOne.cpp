// using Recursion

// #include <bits/stdc++.h>
// using namespace std;

// int solve(int n)
// {
//     if (n == 1)
//         return 0;
//     int ans1 = solve(n - 1);
//     int ans2 = INT_MAX;
//     int ans3 = INT_MAX;
//     if (n % 2 == 0)
//         ans2 = solve(n / 2);
//     if (n % 3 == 0)
//         ans3 = solve(n / 3);
//     int ans = min(ans1, min(ans2, ans3)) + 1;
//     return ans;
// }

// int countStepsToOne(int n)
// {
//     int ans = solve(n);
//     return ans;
// }

// using memoization

// #include <bits/stdc++.h>
// using namespace std;

// int solve(int n, int arr[])
// {
//     if (n == 1)
//         return 0;
//     arr[1] = 0;
//     int ans1;
//     if (arr[n - 1] == -1)
//     {
//         ans1 = solve(n - 1, arr);
//         arr[n - 1] = ans1;
//     }
//     else
//         ans1 = arr[n - 1];
//     int ans2 = INT_MAX;
//     int ans3 = INT_MAX;
//     if (n % 2 == 0)
//     {
//         if (arr[n / 2] == -1)
//         {
//             ans2 = solve(n / 2, arr);
//             arr[n / 2] = ans2;
//         }
//         else
//             ans2 = arr[n / 2];
//     }
//     if (n % 3 == 0)
//     {
//         if (arr[n / 2] == -1)
//         {
//             ans3 = solve(n / 3, arr);
//             arr[n / 3] = ans3;
//         }
//         else
//             ans3 = arr[n / 3];
//     }
//     int ans = min(ans1, min(ans2, ans3)) + 1;
//     return ans;
// }

// int countStepsToOne(int n)
// {
//     int arr[n + 1];
//     for(int i = 0; i <= n; i++){
//         arr[i] = -1;
//     }
//     int ans = solve(n,arr);
//     return ans;
// }

// using tabulation

#include <bits/stdc++.h>
int solve(int n)
{
    if (n == 1)
        return 0;
    int arr[n + 1];
    arr[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        int ans1 = arr[i - 1];
        int ans2 = INT_MAX;
        if (i % 2 == 0)
            ans2 = arr[i / 2];
        int ans3 = INT_MAX;
        if (i % 3 == 0)
            ans3 = arr[i / 3];
        arr[i] = min(ans1, min(ans2, ans3)) + 1;
    }

    return arr[n];
}

int countStepsToOne(int n)
{

    int ans = solve(n);
    return ans;
}