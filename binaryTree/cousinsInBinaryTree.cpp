void solve(TreeNode *root, int x, int y, int parentArr[], int level[], int parent, int currLevel)
{
    if (root == NULL)
        return;
    if (root->val == x)
    {
        parentArr[0] = parent;
        level[0] = currLevel;
    }
    if (root->val == y)
    {
        parentArr[1] = parent;
        level[1] = currLevel;
    }
    if (root->left)
        solve(root->left, x, y, parentArr, level, root->val, currLevel + 1);
    if (root->right)
        solve(root->right, x, y, parentArr, level, root->val, currLevel + 1);
    return;
}
bool isCousins(TreeNode *root, int x, int y)
{
    int parent[2] = {-1, -1};
    int level[2] = {-1, -1};
    solve(root, x, y, parent, level, -1, 0);
    if (parent[0] != parent[1] && level[0] == level[1])
        return true;
    return false;
}