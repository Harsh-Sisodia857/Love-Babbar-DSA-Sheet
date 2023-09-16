#include <bits/stdc++.h>
using namespace std;

// recursive solution

// int lcs(string X, string Y, int m, int n)
// {
//    if(m == 0 || n == 0)
//        return 0;
//    if(X[0] == Y[0])
//        return lcs(X.substr(1), Y.substr(1), m - 1, n - 1) + 1;
//    return max(lcs(X.substr(1), Y, m - 1, n), lcs(X, Y.substr(1), m, n - 1));
// }

// int main()
// {
//     string S1 = "AGGTAB";
//     string S2 = "GXTXAYB";
//     int m = S1.size();
//     int n = S2.size();

//     cout << "Length of LCS is " << lcs(S1, S2, m, n);

//     return 0;
// }

// memoization

// int lcs(string X, string Y, int m, int n,vector<int,vector<int>> dp)
// {
//     if (m == 0 || n == 0)
//         return 0;
//     if (X[m-1] == Y[n-1]){
//         dp[m][n] = lcs(X, Y, m - 1, n - 1) + 1;
//         return dp[m][n];
//     }
//     if(dp[m][n] != -1)
//         return dp[m][n];

//     dp[m][n] = max(lcs(X, Y, m - 1, n), lcs(X, Y, m, n - 1));
//     return dp[m][n];
// }

// int main()
// {
//     string S1 = "AGGTAB";
//     string S2 = "GXTXAYB";
//     int m = S1.size();
//     int n = S2.size();
//     vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
//     cout<< "Length of LCS is " << lcs(S1, S2, m, n,dp);

//     return 0;
// }

// iterative DP
// TOp to bottom
int lcs(string X, string Y, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = m - 1; i >= 0; i--){
        for (int j = n - 1; j >= 0; j--){
            if(X[i] == Y[j])
                dp[i][j] = dp[i + 1][j + 1] + 1;
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
        }
    }
    return dp[0][0];
}

// bottom to top
#include<vector>


int lcs(string s, string t) {
    int l1 = s.length();
    int l2 = t.length();
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1,0));
	
	for(int i = 0; i <= l1; i++){
		for(int j = 0; j <= l2; j++){
			// base case
			if(i == 0 || j == 0)
				dp[i][j] = 0;
			else if(s[i-1] == t[j-1])
				dp[i][j] = 1 + dp[i-1][j-1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
    return dp[l1][l2];
}


int main()
{
    string S1 = "AGGTAB";
    string S2 = "GXTXAYB";
    int m = S1.size();
    int n = S2.size();
    cout << "Length of LCS is " << lcs(S1, S2, m, n);

    return 0;
}