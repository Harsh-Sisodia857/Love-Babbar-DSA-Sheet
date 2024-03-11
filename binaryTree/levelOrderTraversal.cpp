vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == nullptr)
        return ans;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int totalSize = q.size();
        vector<int> currLevel;
        for (int i = 0; i < totalSize; i++)
        {
            TreeNode *topEle = q.front();
            q.pop();
            if (topEle)
                currLevel.push_back(topEle->val);
            if (topEle->left)
            {
                q.push(topEle->left);
            }
            if (topEle->right)
            {
                q.push(topEle->right);
            }
        }
        ans.push_back(currLevel);
    }
    return ans;
}