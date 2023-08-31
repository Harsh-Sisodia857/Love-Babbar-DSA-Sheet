string countAndSay(int n)
{
    if (n == 1)
        return "1";
    string ans = "";
    int freq = 0;
    string s = countAndSay(n - 1); // countAndSay(4) require countAndSay(3)
    for (int i = 0; i < s.length(); i++)
    {
        freq++;
        if (i == s.length() - 1 || s[i] != s[i + 1])
        {
            ans += to_string(freq) + s[i];
            freq = 0;
        }
    }
    return ans;
}