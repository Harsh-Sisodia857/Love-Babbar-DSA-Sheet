class Solution
{
public:
    bool f(TreeNode *root1, TreeNode *root2)
    {
        // root1 and root2 both are NULL
        if (!root1 && !root2)
        {
            return true;
        }
        // only one of root1 or root2 is NULL
        if (!root1 || !root2)
        {
            return false;
        }

        if (root1->val != root2->val)
            return false;
        return f(root1->left, root2->right) && f(root1->right, root2->left);
    }
    bool isSymmetric(TreeNode *root)
    {
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return true;
        return f(root->left, root->right);
    }
};