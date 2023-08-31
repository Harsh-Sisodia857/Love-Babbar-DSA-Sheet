/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *minValue(TreeNode *root)
    {
        while (root->left)
        {
            root = root->left;
        }
        return root;
    }
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == NULL)
            return NULL;
        if (root->val > key)
            root->left = deleteNode(root->left, key);
        else if (root->val < key)
            root->right = deleteNode(root->right, key);
        else
        {
            if (root->left == NULL && root->right == NULL)
            {
                return NULL;
            }
            if (root->left == NULL)
            {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }
            if (root->right == NULL)
            {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }
            TreeNode *minValueInRight = minValue(root->right);
            root->val = minValueInRight->val;
            root->right = deleteNode(root->right, minValueInRight->val);
        }
        return root;
    }
};