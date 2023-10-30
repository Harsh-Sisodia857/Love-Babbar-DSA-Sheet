void traversal(TreeNode *root, vector<int> &v)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        v.push_back(root->val);
        return;
    }
    traversal(root->left, v);
    traversal(root->right, v);
    return;
}
bool leafSimilar(TreeNode *root1, TreeNode *root2)
{
    vector<int> a, b;
    traversal(root1, a);
    traversal(root2, b);
    return (a == b);
}