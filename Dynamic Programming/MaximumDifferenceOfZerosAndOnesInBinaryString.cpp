int maxSubstring(string S)
{
    int count0 = 0;
    int maxi = -1e8;
    for (int i = 0; i < S.length(); i++)
    {
        if (S[i] == '0')
        {
            count0++;
            maxi = max(maxi, count0);
        }
        else if (count0 > 0)
        {
            count0--;
        }
    }
    if (maxi == -1e8)
        return -1;
    return maxi;
}