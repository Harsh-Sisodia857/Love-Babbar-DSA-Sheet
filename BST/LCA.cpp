Node *LCA(Node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;
    if (root->data == n1 || root->data == n2)
        return root;
    Node *left = LCA(root->left, n1, n2);
    Node *right = LCA(root->right, n1, n2);
    if (left == NULL && right == NULL)
        return NULL;
    if (left && right)
        return root;
    if (left)
        return left;
    if (right)
        return right;
}