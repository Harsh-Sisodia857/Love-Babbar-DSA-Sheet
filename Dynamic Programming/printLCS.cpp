#include<bits/stdc++.h>
using namespace std;

void lcs(string s, string t)
{
    int l1 = s.length();
    int l2 = t.length();
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));

    for (int i = 0; i <= l1; i++)
    {
        for (int j = 0; j <= l2; j++)
        {
            // base case
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int len = dp[l1][l2];
    string ans = "";
    for (int k = 1; k <= len; k++)
    {
        ans += "$"; // dummy string
    }
    int i = l1, j = l2; // Initialize i and j here

    while(i > 0 && j > 0 ){
            if(s[i-1] == t[j-1]){
                ans[len-1] = s[i - 1];
                len--;
                i = i - 1;
                j = j - 1;
            }else if(s[i-1] > t[j-1]){
                i--;
            }else{
                j--;
            }
        }
        cout << ans << endl;
}


int main(){
    string s = "abcde";
    string t = "afcge";
    lcs(s,t);
    return 0;
  }