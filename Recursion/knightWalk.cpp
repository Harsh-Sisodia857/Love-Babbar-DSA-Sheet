bool isValid(int x, int y, int N)
{
    if (x >= 0 && y >= 0 && x <= N && y <= N)
        return true;
    return false;
}

void solve(int count, int x, int y, int targetX, int targetY, int N, int &minCount)
{
    if (x == targetX && y == targetY)
    {
        minCount = min(minCount, count);
        return;
    }
    if (x > N || y > N || x < 0 || y < 0)
    {
        return;
    }
    // moves
    int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
    int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};

    for (int i = 0; i < 8; i++)
    {
        int newX = x + dx[i];
        int newY = y + dy[i];

        if (isValid(newX, newY, N))
        {
            count++;
            solve(count, newX, newY, targetX, targetY, N, minCount);
            count--;
        }
    }
}
int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
{
    // Code here
    int x = TargetPos[0];
    int y = TargetPos[1];
    int targetX = KnightPos[0];
    int targetY = KnightPos[1];
    int minCount = INT_MAX;
    solve(0, x, y, targetX, targetY, N, minCount);
    if (minCount == INT_MAX)
        return -1;
    return minCount;
}