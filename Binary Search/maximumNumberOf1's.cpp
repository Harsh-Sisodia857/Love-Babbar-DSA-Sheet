int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    int ans = -1e9;
    int maxIdx = -1;
    int x = 1;
    for (int i = 0; i < n; i++)
    {
        int low = 0;
        int high = m - 1;
        if (high == 0)
        {
            ans = max(ans, 0);
            continue;
        }
        // Finding Lower Bound of 1 ---> First occurence of 1
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (matrix[i][mid] < x)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        int noOfOnes = m - low;
        if (ans < noOfOnes)
        {
            ans = noOfOnes;
            maxIdx = i;
        }
    }
    return maxIdx;
}