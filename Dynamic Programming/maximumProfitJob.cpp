// recursion
class Solution
{
public:
    int f(int idx, int prev, int n, vector<vector<int>> &jobProfit)
    {
        if (idx == n)
        {
            return 0;
        }
        int pick = 0;
        // pick
        if (prev == -1 || jobProfit[idx][0] >= prev)
            pick = jobProfit[idx][2] + f(idx + 1, jobProfit[idx][1], n, jobProfit);
        int notPick = 0 + f(idx + 1, prev, n, jobProfit);
        return max(pick, notPick);
    }
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if (a[1] != b[1])
        {
            return a[1] < b[1];
        }
        return a[2] > b[2];
    }
    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        int n = startTime.size();
        vector<vector<int>> jobProfit(n, vector<int>(3, 0));
        for (int i = 0; i < n; i++)
        {
            jobProfit[i][0] = startTime[i];
            jobProfit[i][1] = endTime[i];
            jobProfit[i][2] = profit[i];
        }
        sort(jobProfit.begin(), jobProfit.end(), cmp);
        return f(0, -1, n, jobProfit);
    }
};

// memoization
class Solution
{
public:
    int f(int idx, int prev, int n, vector<vector<int>> &jobProfit, vector<vector<int>> &dp)
    {
        if (idx == n)
        {
            return 0;
        }
        if (dp[idx][prev + 1] != -1)
        {
            return dp[idx][prev + 1];
        }
        int pick = 0;
        // pick
        if (prev == -1 || jobProfit[idx][0] >= jobProfit[prev][1])
            pick = jobProfit[idx][2] + f(idx + 1, idx, n, jobProfit, dp);
        int notPick = 0 + f(idx + 1, prev, n, jobProfit, dp);
        return dp[idx][prev + 1] = max(pick, notPick);
    }

    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if (a[1] != b[1])
        {
            return a[1] < b[1];
        }
        return a[2] > b[2];
    }

    int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        int n = startTime.size();
        vector<vector<int>> jobProfit(n, vector<int>(3, 0));
        for (int i = 0; i < n; i++)
        {
            jobProfit[i][0] = startTime[i];
            jobProfit[i][1] = endTime[i];
            jobProfit[i][2] = profit[i];
        }
        sort(jobProfit.begin(), jobProfit.end(), cmp);
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(0, -1, n, jobProfit, dp);
    }
};

// tabulation
class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b) {
        if (a[1] != b[1]) {
            return a[1] < b[1];
        }
        return a[2] > b[2];
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>> jobProfit(n, vector<int>(3, 0));
        for (int i = 0; i < n; i++) {
            jobProfit[i][0] = startTime[i];
            jobProfit[i][1] = endTime[i];
            jobProfit[i][2] = profit[i];
        }
        sort(jobProfit.begin(), jobProfit.end(), cmp);
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));
        for(int idx = n - 1; idx >= 0; idx--){
            for(int prev = idx-1; prev >= -1; prev--){
                int pick = 0;
                // pick
                if (prev == -1 || jobProfit[idx][0] >= jobProfit[prev][1])
                    pick = jobProfit[idx][2] + f(idx + 1, idx, n, jobProfit, dp);
                int notPick = 0 + f(idx + 1, prev, n, jobProfit, dp);
                dp[idx][prev + 1] = max(pick,notPick);
            }
        }

        return dp[0][0];
    }
};

