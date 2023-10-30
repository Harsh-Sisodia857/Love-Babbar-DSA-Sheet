Node *createTree(int parent[], int N)
{
    Node *root = NULL;
    unordered_map<int, Node *> m;
    for (int i = 0; i < N; i++)
    {
        if (parent[i] == -1)
        {
            root = new Node(i);
            m[i] = root;
        }
        else
        {
            Node *temp = new Node(i);
            m[i] = temp;
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (parent[i] == -1)
            continue;
        else
        {
            Node *temp = m[parent[i]];
            if (temp->left == NULL)
                temp->left = m[i];
            else
                temp->right = m[i];
        }
    }
    return root;
}