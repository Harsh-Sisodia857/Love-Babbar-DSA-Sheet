vector<int> leftView(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            auto topEle = q.front();
            q.pop();
            if (i == 0)
            {
                ans.push_back(topEle->data);
            }
            if (topEle->left)
                q.push(topEle->left);
            if (topEle->right)
                q.push(topEle->right);
        }
    }
    return ans;
}