
class NodeValue
{
public:
    int mini, int maxi, int size;
    NodeValue(int mini, int maxi, int size)
    {
        this->mini = mini;
        this->maxi = maxi;
        this->size = size;
    }
};

NodeValue solve(Node *root)
{
    if (root == NULL)
        return NodeValue(INT_MAX, INT_MIN, 0);

    NodeValue left = solve(root->left);
    NodeValue right = solve(root->right);
    if (left.maxi < root->data && right.mini > root->data)
    {
        return NodeValue(min(left.mini, root->data),
                         max(right.max, root->data), max(left.size, right.size) + 1);
    }
    return NodeValue(INT_MAX, INT_MIN, max(left.size, right.size));
}

int largestBst(Node *root)
{
    return solve(Node * root).size;
}