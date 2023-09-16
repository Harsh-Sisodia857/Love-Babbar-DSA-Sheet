// Recursion
int f(vector<vector<int>> &points, int day, int last)
{
    if (day == 0)
    {
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
                maxi = max(maxi, points[0][i]);
        }
        return maxi;
    }
    int maxi = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            int p = points[day][i] + f(points, day - 1, i);
            maxi = max(maxi, p);
        }
    }
    return maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    return f(points, n - 1, 3);
}

// memoization
int f(vector<vector<int>> &points, int day, int last, vector<vector<int>> &dp)
{
    if (day == 0)
    {
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
                maxi = max(maxi, points[0][i]);
        }
        return maxi;
    }
    if (dp[day][last] != -1)
        return dp[day][last];
    int maxi = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            int p = points[day][i] + f(points, day - 1, i, dp);
            maxi = max(maxi, p);
        }
    }
    return dp[day][last] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return f(points, n - 1, 3, dp);
}

// Tabulation
int f(vector<vector<int>> &points, int days, int last)
{
    vector<vector<int>> dp(days, vector<int>(4, 0));
    // Base case
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][1], points[0][0]);
    dp[0][3] = max(max(points[0][0], points[0][1]), points[0][2]);

    for (int day = 1; day < days; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            int maxi = 0;
            for (int i = 0; i < 3; i++)
            {
                if (i != last)
                {
                    int p = points[day][i] + dp[day - 1][i];
                    maxi = max(maxi, p);
                }
            }
            dp[day][last] = maxi;
        }
    }

    return dp[days - 1][last];
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    return f(points, n, 3);
}