long long findMinDiff(vector<long long> a, long long n, long long m)
{
    sort(a.begin(), a.end());
    long long mini = INT_MAX;
    /* 3, 4, 1, 9, 56, 7, 9, 12
       |            |
       i            j
          |            |
          i            j
             |            |
             i            j
                |            |
                i            j      */
    int i = 0, j = m - 1;
    while (j < n)
    {
        mini = min(mini, a[j] - a[i]);
        i++;
        j++;
    }
    return mini;
}