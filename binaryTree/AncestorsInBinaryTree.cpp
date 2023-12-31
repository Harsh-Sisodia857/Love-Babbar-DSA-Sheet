bool solve(struct Node *root, int target, vector<int> &ans)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == target)
    {
        return true;
    }

    ans.push_back(root->data);
    if (root->left)
    {
        if (solve(root->left, target, ans))
            return true;
    }

    if (root->right)
    {
        if (solve(root->right, target, ans))
            return true;
    }
    ans.pop_back();

    return false;
}
vector<int> Ancestors(struct Node *root, int target)
{
    vector<int> ans;
    solve(root, target, ans);
    reverse(ans.begin(), ans.end());
    return ans;
}