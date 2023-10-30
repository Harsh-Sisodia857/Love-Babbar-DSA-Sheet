class Solution
{
public:
    void inorder(struct Node *root, vector<Node *> &v)
    {
        if (root)
        {
            inorder(root->left, v);
            v.push_back(root);
            inorder(root->right, v);
        }
    }
    void transformTree(struct Node *root)
    {
        if (root == NULL)
            return;
        vector<Node *> v;
        inorder(root, v);
        vector<int> a;
        int sum = 0;
        a.push_back(0);
        for (int i = v.size() - 1; i >= 0; i--)
        {
            if (i != (v.size() - 1))
                a.push_back(sum);
            sum += v[i]->data;
        }
        reverse(a.begin(), a.end());

        for (int i = 0; i < a.size(); i++)
        {
            v[i]->data = a[i];
        }
    }
};