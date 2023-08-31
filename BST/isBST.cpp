bool isValid(Node *root, int min, int max)
{
    if (root == NULL)
        return true;
    if (root->data < max && root->data > min)
    {
        bool l = isValid(root->left, min, root->data);
        bool r = isValid(root->right, root->data, max);
        return (l && r);
    }
    return false;
}
bool isBST(Node *root)
{
    return isValid(root, INT_MIN, INT_MAX);
}