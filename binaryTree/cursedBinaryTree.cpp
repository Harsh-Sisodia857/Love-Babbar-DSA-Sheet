class Solution
{
public:
    int traverseTree(Node *root, int left, int right)
    {
        int possibleMaxSum = 0;
        if (left > 0 && root->left != NULL)
        {
            possibleMaxSum = max(possibleMaxSum, traverseTree(root->left, left - 1, right));
        }
        if (right > 0 && root->right != NULL)
        {
            possibleMaxSum = max(possibleMaxSum, traverseTree(root->right, left, right - 1));
        }
        possibleMaxSum = possibleMaxSum + root->data;
        return possibleMaxSum;
    }
    void goDeep(Node *root, int k, int &maxSum)
    {
        maxSum = max(maxSum, traverseTree(root, k, k));
        if (root->left)
            goDeep(root->left, k, maxSum);
        if (root->right)
            goDeep(root->right, k, maxSum);
    }
    int maximumSum(int n, Node *root, int k)
    {
        int maxSum = 0;
        goDeep(root, k, maxSum);
        return maxSum;
    }
};
