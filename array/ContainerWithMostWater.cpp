int maxArea(vector<int> &height)
{
    int low = 0;
    int high = height.size() - 1;
    int maxi = INT_MIN;
    while (low < high)
    {
        int area = (high - low) * (min(height[low], height[high]));
        maxi = max(area, maxi);
        if (height[high] > height[low])
        {
            low++;
        }
        else
        {
            high--;
        }
    }
    return maxi;
}