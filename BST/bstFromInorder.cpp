void getInorder(Node *root, vector<int> &inorder)
{
    if (root)
    {
        getInorder(root->left, inorder);
        inorder.push_back(root->data);
        getInorder(root->right, inorder);
    }
    return;
}
Node *createBST(int n, vector<int> inorder, int start, int end)
{

    if (start <= end)
    {
        int mid = (start + end) / 2;
        Node *root = new Node(inorder[mid]);
        root->left = createBST(n, inorder, start, mid - 1);
        root->right = createBST(n, inorder, mid + 1, end);
        return root;
    }
    return NULL;
}
Node *binaryTreeToBST(Node *root)
{
    vector<int> inorder;
    getInorder(root, inorder);
    sort(inorder.begin(), inorder.end());
    int n = inorder.size();
    Node *temp = createBST(n, inorder, 0, n - 1);
    return temp;
}