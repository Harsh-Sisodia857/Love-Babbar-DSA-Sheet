// recursion
bool isAllStar(int pos,string s1){
   for(int i = 0; i <= pos; i++){
      if(s1[i] != '*')
         return false;
   }
   return true;
}

bool f(int i,int j,int n,int m,string s1, string s2){
   // base condition
   if(i < 0 && j >= 0)
      return false;
   if(i < 0 && j < 0)
      return true;
   if(i >= 0 && j < 0)
      return isAllStar(i,s1);

   if(s1[i] == s2[j] || s1[i] == '?')
      return f(i-1,j-1,n,m,s1,s2);
   if(s1[i] == '*')
      return f(i-1,j,n,m,s1,s2) + f(i,j-1,n,m,s1,s2);
   return false;
}

bool wildcardMatching(string pattern, string text)
{
   int n = pattern.length();
   int m = text.length();
   return f(n-1,m-1,n,m,pattern,text);
}

// memoization

#include <vector>
bool isAllStar(int pos, string s1)
{
   for (int i = 0; i <= pos; i++)
   {
      if (s1[i] != '*')
         return false;
   }
   return true;
}

bool f(int i, int j, int n, int m, string s1, string s2, vector<vector<int>> &dp)
{
   // base condition
   if (i < 0 && j >= 0)
      return false;
   if (i < 0 && j < 0)
      return true;
   if (i >= 0 && j < 0)
      return isAllStar(i, s1);

   if (dp[i][j] != -1)
      return dp[i][j];

   if (s1[i] == s2[j] || s1[i] == '?')
      return dp[i][j] = f(i - 1, j - 1, n, m, s1, s2, dp);
   if (s1[i] == '*')
      return dp[i][j] = f(i - 1, j, n, m, s1, s2, dp) + f(i, j - 1, n, m, s1, s2, dp);
   return dp[i][j] = false;
}

bool wildcardMatching(string pattern, string text)
{
   int n = pattern.length();
   int m = text.length();
   vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
   return f(n - 1, m - 1, n, m, pattern, text, dp);
}

// tabulation
#include <vector>
bool isAllStar(int pos, string s1)
{
   for (int i = 0; i < pos; i++)
   {
      if (s1[i] != '*')
         return false;
   }
   return true;
}

bool wildcardMatching(string pattern, string text)
{
   int n = pattern.length();
   int m = text.length();
   vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
   dp[0][0] = true;
   for (int j = 1; j < m + 1; j++)
      dp[0][j] = false;
   for (int i = 1; i < n + 1; i++)
   {
      dp[i][0] = isAllStar(i, pattern);
   }

   for (int i = 1; i < n + 1; i++)
   {
      for (int j = 1; j < m + 1; j++)
      {
         if (pattern[i - 1] == text[j - 1] || pattern[i - 1] == '?')
             dp[i][j] = dp[i - 1][j - 1];
         else
         {
             if (pattern[i - 1] == '*')
                 dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
             else
                 dp[i][j] = false;
         }
      }
   }

   return dp[n][m];
}
