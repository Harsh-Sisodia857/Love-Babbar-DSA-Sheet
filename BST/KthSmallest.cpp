//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
int kthLargest(Node *root, int K, vector<int> &inorder);
void morrisTraversal(Node *root, vector<int> &inorder)
{
    if (root == NULL)
        return;

    Node *curr = root;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            inorder.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            Node *prev = curr->left;
            while (prev->right && prev->right != curr)
            {
                prev = prev->right;
            }
            if (prev->right == NULL)
            {
                prev->right = curr;
                curr = curr->left;
            }
            else
            {
                prev->right = NULL;
                inorder.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    // cout << "\nINORDER SIZE : " << inorder.size() << endl;
    // for (auto it : inorder)
    //     cout << it << " ";
}

int kthLargest(Node *root, int K, vector<int> &inorder)
{
    morrisTraversal(root, inorder);

    int size = inorder.size();
    int t = K-1;
    return inorder[t];
}

int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(9);
    vector<int> inorder;
    morrisTraversal(root, inorder);
    int k;
    cin >> k;
    cout << "Kth Smallest Element : " << kthLargest(root, k, inorder);
    return 0;
}
// } Driver Code Ends