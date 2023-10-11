
int f(Node *root){
    if(root == NULL)
        return 0;
    // pick
    int pick = 1;
    if(root->left)
        pick = pick + f(root->left->left) + f(root->left->right);
    if(root->right)
        pick = pick + f(root->right->left) + f(root->right->right);
    // not pick
    int notPick = f(root->left) + f(root->right);
    return max(pick,notPick);
}

int LISS(Node *root)
{
    return f(root);
}