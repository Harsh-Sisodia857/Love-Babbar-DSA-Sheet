bool isAnagram(string s1, string s2)
{
    if (s1.length() != s2.length())
        return false;
    int n = s1.length();
    char count1[256] = {0};
    char count2[256] = {0};
    for (int i = 0; i < n; i++)
    {
        count1[s1[i]]++;
        count2[s2[i]]++;
    }
    for (int i = 0; i < 256; i++)
    {
        if (count1[i] != count2[i])
            return false;
    }
    return true;
}
vector<int> howManyAreAnagrams(int n, int m, vector<string> &a, vector<string> &b)
{
    // Write your code here.
    vector<int> ans;
    for (int i = 0; i < m; i++)
    {
        string temp = b[i];
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (isAnagram(temp, a[j]))
                count++;
        }
        ans.push_back(count);
    }
    return ans;
}