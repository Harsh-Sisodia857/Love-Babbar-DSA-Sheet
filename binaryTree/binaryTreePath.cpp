void solve(TreeNode *root, vector<string> &ans, string s)
{
    if (root == NULL)
        return;
    if (!root->left && !root->right)
    {
        s += to_string(root->val);
        ans.push_back(s);
        return;
    }
    string currVal = to_string(root->val) + "->";
    if (root->left)
        solve(root->left, ans, s + currVal);
    if (root->right)
        solve(root->right, ans, s + currVal);
    return;
}
vector<string> binaryTreePaths(TreeNode *root)
{
    vector<string> ans;
    string s = "";
    solve(root, ans, s);
    return ans;
}