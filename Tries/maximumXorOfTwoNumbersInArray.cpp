class TrieNode
{
public:
    TrieNode *left;
    TrieNode *right;
    TrieNode()
    {
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    TrieNode *head = new TrieNode();

    void insert(int x)
    {
        TrieNode *t = head;
        bitset<32> bs(x);
        for (int i = 31; i >= 0; i--)
        {
            if (bs[i])
            {
                if (t->right)
                {
                    t = t->right;
                }
                else
                {
                    t->right = new TrieNode();
                    t = t->right;
                }
            }
            else
            {
                if (t->left)
                {
                    t = t->left;
                }
                else
                {
                    t->left = new TrieNode();
                    t = t->left;
                }
            }
        }
    }

    int helper(int x)
    {
        bitset<32> bs(x);
        int maxXor = 0;
        TrieNode *child = head;
        for (int i = 31; i >= 0; i--)
        {
            int bit = bs[i];
            if (bit)
            {
                if (child->left)
                {
                    maxXor += (1 << i);
                    child = child->left;
                }
                else if (child->right)
                {
                    child = child->right;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if (child->right)
                {
                    maxXor += (1 << i);
                    child = child->right;
                }
                else if (child->left)
                {
                    child = child->left;
                }
                else
                {
                    break;
                }
            }
        }
        return maxXor;
    }

    int findMaximumXOR(vector<int> &nums)
    {
        int n = nums.size();
        insert(nums[0]);
        int maxi = INT_MIN;
        for (int i = 1; i < n; i++)
        {
            maxi = max(helper(nums[i]), maxi);
            insert(nums[i]);
        }
        return maxi == INT_MIN ? 0 : maxi;
    }
};