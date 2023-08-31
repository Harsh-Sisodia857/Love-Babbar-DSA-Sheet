void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    pre = NULL;
    Node *temp = root;
    while (temp != NULL)
    {
        if (key <= temp->key)
        {
            temp = temp->left;
        }
        else
        {
            pre = temp;
            temp = temp->right;
        }
    }
    suc = NULL;

    while (root != NULL)
    {
        if (key >= root->key)
        {
            root = root->right;
        }
        else
        {
            suc = root;
            root = root->left;
        }
    }
}