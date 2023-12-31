class Solution
{
public:
    void findPairs(map<char, string> phone, string digits, vector<string> &ans, string s, int currIdx)
    {
        if (currIdx >= digits.length())
        {
            ans.push_back(s);
            return;
        }
        int currNum = digits[currIdx];
        string alpha = phone[currNum];
        for (int i = 0; i < alpha.length(); i++)
        {
            s.push_back(alpha[i]);
            findPairs(phone, digits, ans, s, currIdx + 1);
            s.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits)
    {
        map<char, string> phone{
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        vector<string> ans;
        string s = "";
        if (digits.size() == 0)
            return ans;
        findPairs(phone, digits, ans, s, 0);
        return ans;
    }
};