int getLevelDiff(Node *root)
{
    queue<Node *> q;
    q.push(root);
    int EvenSum = 0, OddSum = 0, flag = false;
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *frontNode = q.front();
            if (flag == false)
            {
                OddSum += frontNode->data;
            }
            else
            {
                EvenSum += frontNode->data;
            }
            q.pop();
            if (frontNode->left)
            {
                q.push(frontNode->left);
            }
            if (frontNode->right)
                q.push(frontNode->right);
        }
        flag = !flag;
    }
    return (OddSum - EvenSum);
}