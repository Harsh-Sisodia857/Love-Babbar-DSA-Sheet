// brute force
bool isPossible(vector<int> &stalls, int dist, int cows)
{
    int cowCount = 1;
    int n = stalls.size();
    int prev = stalls[0];
    for (int i = 1; i < n; i++)
    {
        int currDist = stalls[i] - prev;
        if (currDist >= dist)
        {
            cowCount++;
            prev = stalls[i];
        }
        if (cowCount >= cows)
            return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());
    int limitCow = stalls[n - 1] - stalls[0];
    for (int i = 1; i < limitCow; i++)
    {
        if (isPossible(stalls, i, k) == false)
            return i - 1;
    }
    return limitCow;
}

// optimal approach
bool isPossible(vector<int> &stalls, int dist, int cows)
{
    int cowCount = 1;
    int n = stalls.size();
    int prev = stalls[0];
    for (int i = 1; i < n; i++)
    {
        int currDist = stalls[i] - prev;
        if (currDist >= dist)
        {
            cowCount++;
            prev = stalls[i];
        }
        if (cowCount >= cows)
            return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());
    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isPossible(stalls, mid, k))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
}