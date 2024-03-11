bool isValid(int row, int col, vector<vector<bool>> &vis, vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    if (row >= 0 && row < n && col >= 0 && col < m && !vis[row][col] && grid[row][col] == 'X')
    {
        return true;
    }
    return false;
}

void bfs(int r, int c, vector<vector<bool>> &vis, vector<vector<char>> &grid)
{
    queue<pair<int, int>> q;
    q.push({r, c});
    vis[r][c] = true;
    while (!q.empty())
    {
        int currRow = q.front().first;
        int currCol = q.front().second;
        q.pop();
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        for (int i = 0; i < 4; i++)
        {
            int row = currRow + dx[i];
            int col = currCol + dy[i];
            if (isValid(row, col, vis, grid))
            {
                q.push({row, col});
                vis[row][col] = true;
            }
        }
    }
}

int xShape(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (isValid(i, j, vis, grid))
            {
                count++;
                bfs(i, j, vis, grid);
            }
        }
    }
    return count;
}