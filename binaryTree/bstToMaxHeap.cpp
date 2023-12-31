
class Solution
{
public:
    int idx = 0;
    vector<int> v;
    void inorder(Node *root)
    {
        if (root)
        {
            inorder(root->left);
            v.push_back(root->data);
            inorder(root->right);
        }
    }
    void postOrder(Node *root)
    {
        if (root)
        {
            postOrder(root->left);
            postOrder(root->right);
            root->data = v[idx++];
        }
    }
    void convertToMaxHeapUtil(Node *root)
    {
        // postorder of max heap is sorted
        inorder(root);
        postOrder(root);
    }
};