int solve(Node *root)
{
    if (root == NULL)
        return 0;
    int temp = root->data;
    int left = solve(root->left);
    int right = solve(root->right);
    int toReturn = (left + right + temp);
    root->data = left + right;
    return toReturn;
}
void toSumTree(Node *node)
{
    solve(node);
}