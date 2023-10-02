struct val
{
    int first;
    int second;
};

static bool cmp(val a, val b)
{
    if (a.second == b.second)
    {
        return b.first > a.first;
    }
    return a.second < b.second;
}
int maxChainLen(struct val p[], int n)
{

    sort(p, p + n, cmp);
    int x = p[0].second, cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (p[i].first > x)
        {
            x = p[i].second;
            cnt++;
        }
    }
    return cnt;
}