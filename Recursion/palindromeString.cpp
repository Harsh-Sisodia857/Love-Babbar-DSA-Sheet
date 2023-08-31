class Solution
{
public:
    bool isPalindrome(string s, int start, int end)
    {
        while (start <= end)
        {
            if (s[start++] != s[end--])
            {
                return false;
            }
        }
        return true;
    }

    void generate(int idx, vector<vector<string>> &ans, vector<string> path, string s, int n)
    {
        if (idx == n)
        {
            ans.push_back(path);
            return;
        }
        for (int i = idx; i < n; i++)
        {
            if (isPalindrome(s, idx, i))
            {
                path.push_back(s.substr(idx, i - idx + 1));
                generate(i + 1, ans, path, s, n);
                path.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        int n = s.length();
        vector<vector<string>> ans;
        vector<string> path;
        generate(0, ans, path, s, n);
        return ans;
    }
};