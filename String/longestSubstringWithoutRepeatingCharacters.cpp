int lengthOfLongestSubstring(string s)
{
    int n = s.length();
    cout << "Len : " << n;
    if (n == 0 || n == 1)
        return n;
    vector<int> vis(256, 0);
    int right = 0, left = 0, maxLength = 0;
    while (right < n)
    {
        if (vis[s[right]] == 1)
        {
            while (vis[s[right]])
            {
                vis[s[left]] = 0;
                left++;
            }
        }
        vis[s[right]] = 1;
        maxLength = max(maxLength, (right - left + 1));
        right++;
    }
    return maxLength;
}