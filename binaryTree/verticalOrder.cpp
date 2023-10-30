vector<int> verticalOrder(Node *root)
{
    queue<pair<int, Node *>> q;
    q.push({0, root});
    map<int, vector<int>> m;
    while (!q.empty())
    {
        pair<int, Node *> frontNode = q.front();
        int hdis = frontNode.first;
        Node *currNode = frontNode.second;
        q.pop();
        m[hdis].push_back(currNode->data);
        if (currNode)
        {
            if (currNode->left)
            {
                q.push({hdis - 1, currNode->left});
            }
            if (currNode->right)
            {
                q.push({hdis + 1, currNode->right});
            }
        }
    }
    vector<int> ans;
    for (auto it : m)
    {
        for (auto j : it.second)
            ans.push_back(j);
    }
    return ans;
}