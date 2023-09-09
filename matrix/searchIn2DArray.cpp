bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    // row
    int n = matrix.size();
    // col
    int m = matrix[0].size();
    int low = 0;
    int high = (n * m) - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int r = (mid / m);
        int c = (mid % m);
        if (matrix[r][c] == target)
            return true;
        else if (matrix[r][c] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return false;
}