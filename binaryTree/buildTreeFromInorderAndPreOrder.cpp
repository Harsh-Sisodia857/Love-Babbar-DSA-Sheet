//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printPostOrder(Node *root)
{
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution
{
public:
    int findIdx(int in[], int ele, int start, int n)
    {

        for (int i = start; i <= n; i++)
        {
            if (in[i] == ele)
                return i;
        }
        return -1;
    }
    Node *solve(int in[], int pre[], int &preIdx, int start, int end, int n)
    {
        if (start > end || preIdx >= n)
            return NULL;
        int ele = pre[preIdx];
        Node *root = new Node(ele);
        preIdx++;
        int idx = findIdx(in, ele, start, end);

        root->left = solve(in, pre, preIdx, start, idx - 1, n);
        root->right = solve(in, pre, preIdx, idx + 1, end, n);
        return root;
    }
    Node *buildTree(int in[], int pre[], int n)
    {
        Node *root = NULL;
        int preIdx = 0;
        root = solve(in, pre, preIdx, 0, n - 1, n);
        return root;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int inorder[n], preorder[n];
        for (int i = 0; i < n; i++)
            cin >> inorder[i];
        for (int i = 0; i < n; i++)
            cin >> preorder[i];
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder, n);
        printPostOrder(root);
        cout << endl;
    }
}

// } Driver Code Ends