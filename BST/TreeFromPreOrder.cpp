Node *solve(int pre[], int *idx, int size, int max, int min)
{
    if (*idx >= size)
        return NULL;
    if (pre[*idx] < min || pre[*idx] > max)
        return NULL;
    int node = pre[*idx];
    Node *root = newNode(node);
    *idx = *idx + 1;
    root->left = solve(pre, idx, size, node, min);
    root->right = solve(pre, idx, size, max, node);
    return root;
}
// Function that constructs BST from its preorder traversal.
Node *post_order(int pre[], int size)
{
    int idx = 0;
    Node *root = solve(pre, &idx, size, INT_MAX, INT_MIN);
    return root;
}