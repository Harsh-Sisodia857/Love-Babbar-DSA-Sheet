#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int pseudoPalindromicPaths(TreeNode *root)
    {
        int count = 0;
        vector<int> pathCount(10, 0);
        preorder(root, pathCount, count);
        return count;
    }

    void preorder(TreeNode *root, vector<int> &pathCount, int &count)
    {
        if (root == nullptr)
        {
            return;
        }

        pathCount[root->val]++;

        if (root->left == nullptr && root->right == nullptr)
        {
            if (isPseudoPalindromic(pathCount))
            {
                count++;
            }
        }

        preorder(root->left, pathCount, count);
        preorder(root->right, pathCount, count);

        // Backtrack
        pathCount[root->val]--;
    }

    bool isPseudoPalindromic(const vector<int> &pathCount)
    {
        int oddCount = 0;
        for (int i = 1; i < 10; i++)
        {
            if (pathCount[i] % 2 == 1)
            {
                oddCount++;
            }
        }
        return oddCount <= 1;
    }
};

int main()
{
    Solution solution;

    TreeNode *root = new TreeNode(8);
    root->left = new TreeNode(8);
    root->left->right = new TreeNode(7);
    root->left->right->right = new TreeNode(2);
    root->left->right->right->right = new TreeNode(4);
    root->left->right->right->right->right = new TreeNode(8);
    root->right = new TreeNode(7);
    root->right->left = new TreeNode(1);

    int result = solution.pseudoPalindromicPaths(root);
    cout << "Number of pseudo-palindromic paths: " << result << endl;

    return 0;
}
