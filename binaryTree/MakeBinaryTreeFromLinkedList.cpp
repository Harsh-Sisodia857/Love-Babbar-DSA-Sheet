// Function to make binary tree from linked list.
TreeNode *f(int idx, unordered_map<int, Node *> &m)
{
    if (m.find(idx) == m.end() || m[idx] == NULL)
    {
        return NULL;
    }
    int val = m[idx]->data;
    TreeNode *node = new TreeNode(val);
    // left node
    int leftIdx = 2 * idx + 1;
    int rightIdx = 2 * idx + 2;
    node->left = f(leftIdx, m);
    node->right = f(rightIdx, m);
    return node;
}

void convert(Node *head, TreeNode *&root)
{
    if (head == NULL)
    {
        root = NULL;
        return;
    }

    // Your code here
    unordered_map<int, Node *> m;
    Node *curr = head;
    int i = 0;
    while (curr != NULL)
    {
        m[i++] = curr;
        curr = curr->next;
    }

    root = f(0, m);
}