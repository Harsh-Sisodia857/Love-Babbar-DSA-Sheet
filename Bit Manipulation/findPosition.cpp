int findPosition(int N)
{
    int n = N;
    if (n && (n & (n - 1)) == 0)
    {
        int count = 0;
        while (n)
        {
            count++;
            n = (n >> 1);
        }
        return count;
    }
    else
    {
        return -1;
    }
}