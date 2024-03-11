class Solution
{
public:
    int M = 1e9 + 7;
    int dfs(int row, int col, int maxMove, int n, int m)
    {
        if (row < 0 || col < 0 || row >= n || col >= m)
        {
            return 1;
        }
        if (maxMove <= 0)
        {
            return 0;
        }
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        long long paths = 0;
        for (int i = 0; i < 4; i++)
        {
            int x = dx[i] + row;
            int y = dy[i] + col;
            if (maxMove > 0)
            {
                paths += (dfs(x, y, maxMove - 1, n, m) % M);
                paths %= M;
            }
        }
        return paths;
    }
    int findPaths(int n, int m, int maxMove, int startRow, int startCol)
    {
        return dfs(startRow, startCol, maxMove, n, m);
    }
};