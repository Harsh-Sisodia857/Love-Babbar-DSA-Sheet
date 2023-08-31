class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.length() == 1)
            return s;

        int size = s.length();
        int low;
        int high;
        int maxLen = 1;
        int st = 0; // Initialize st to 0
        for (int i = 1; i < size; i++)
        {
            // even case
            low = i - 1;
            high = i;
            while (low >= 0 && high < size && s[low] == s[high])
            {
                int currLen = high - low + 1;
                if (currLen > maxLen)
                {
                    maxLen = currLen;
                    st = low;
                }
                low--;
                high++;
            }
            // odd case
            low = i - 1;
            high = i + 1;
            while (low >= 0 && high < size && s[low] == s[high])
            {
                int currLen = high - low + 1;
                if (currLen > maxLen)
                {
                    maxLen = currLen;
                    st = low;
                }
                low--;
                high++;
            }
        }

        return s.substr(st, maxLen);
    }
};