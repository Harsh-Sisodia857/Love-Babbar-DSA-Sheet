Node *inOrderSuccessor(Node *root, Node *x)
{
    if (root == NULL)
        return NULL;
    Node *curr = root;
    Node *succ = NULL;
    while (curr)
    {
        if (curr->data > x->data)
        {
            succ = curr;
            curr = curr->left;
        }
        else if (curr->data < x->data)
        {
            curr = curr->right;
        }
        else
        {
            break;
        }
    }
    Node *minValue = curr->right;
    while (minValue)
    {
        succ = minValue;
        minValue = minValue->left;
    }
    return succ;
}