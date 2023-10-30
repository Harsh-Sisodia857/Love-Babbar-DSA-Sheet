void solve(TreeNode *root, int &path, string s)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        s += to_string(root->val);
        path += stoi(s, 0, 2);
        return;
    }
    string currVal = to_string(root->val);

    if (root->left)
        solve(root->left, path, s + currVal);
    if (root->right)
        solve(root->right, path, s + currVal);
}
int sumRootToLeaf(TreeNode *root)
{
    int path = 0;
    solve(root, path, "");
    return path;
}