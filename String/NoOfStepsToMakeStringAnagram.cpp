class Solution
{
public:
    int minSteps(string s, string t)
    {
        vector<int> v1(26, 0);
        vector<int> v2(26, 0);
        for (int i = 0; i < s.length(); i++)
        {
            v1[s[i] - 'a']++;
            v2[t[i] - 'a']++;
        }
        int steps = 0;
        for (int i = 0; i < 26; i++)
        {
            steps += abs(v1[i] - v2[i]);
        }
        return (steps / 2);
    }
};