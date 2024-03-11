vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int n = image.size();
    int m = image[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    q.push({sr, sc});
    vis[sr][sc] = 1;
    int startingPixelColor = image[sr][sc];
    while (!q.empty())
    {
        int nRow = q.front().first;
        int nCol = q.front().second;
        if (startingPixelColor == image[nRow][nCol])
            image[nRow][nCol] = color;

        q.pop();
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        for (int i = 0; i < 4; i++)
        {
            int currRow = nRow + dx[i];
            int currCol = nCol + dy[i];
            if (currRow >= 0 && currRow < n && currCol >= 0 && currCol < m && !vis[currRow][currCol] && startingPixelColor == image[currRow][currCol])
            {
                image[currRow][currCol] = color;
                vis[currRow][currCol] = true;
                q.push({currRow, currCol});
            }
        }
    }
    return image;
}