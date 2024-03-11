bool isValid(int row, int col, vector<vector<int>> &grid, vector<vector<bool>> &vis)
{
    int r = grid.size();
    int c = grid[0].size();
    if (row >= 0 && row < r && col >= 0 && col < c && grid[row][col] != 0 && !vis[row][col])
    {
        return true;
    }
    return false;
}

bool is_Possible(vector<vector<int>> &grid)
{
    // code here
    int sr = 0;
    int sc = 0;
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<bool>> vis(row, vector<bool>(col, false));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (grid[i][j] == 1)
            {
                sr = i;
                sc = j;
            }
        }
    }
    queue<pair<int, int>> q;
    q.push({sr, sc});
    vis[sr][sc] = true;
    while (!q.empty())
    {
        int currRow = q.front().first;
        int currCol = q.front().second;
        q.pop();
        if (grid[currRow][currCol] == 2)
        {
            return true;
        }
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        for (int i = 0; i < 4; i++)
        {
            int r = currRow + dx[i];
            int c = currCol + dy[i];

            if (isValid(r, c, grid, vis))
            {
                vis[r][c] = true;
                q.push({r, c});
            }
        }
    }
    return false;
}