
bool solve(Node *root, int min, int max)
{
    if (root == NULL)
        return false;
    if (min == max)
        return true;
    if (solve(root->left, min, (root->data - 1)) || solve(root->right, (root->data + 1), max))
        return true;
    return false;
}

bool isDeadEnd(Node *root)
{
    return solve(root, 1, INT_MAX);
}