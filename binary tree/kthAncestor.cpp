#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
    node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

node *kthLCA(node *root, int n1, int n2, int &k,int &ans)
{
    if (root == NULL)
        return NULL;
    if (root->data == n1 || root->data == n2)
        return root;
    node *left = kthLCA(root->left, n1, n2, k,ans);
    node *right = kthLCA(root->right, n1, n2, k,ans);
    if (left == NULL && right == NULL)
        return NULL;
    if (left && right)
    {
        k--;
        if (k == 0)
        {
            k = INT_MAX;
            ans = root->data;
        }
        return root;
    }
    if (right)
    {
        k--;
        if (k == 0)
        {
            k = INT_MAX;
            ans = root->data;
        }
        return right;
    }
    if(left)
    {
        k--;
        if (k == 0)
        {
            k = INT_MAX;
            ans = root->data;
        }
        return left;
    }
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    int ans = -1;
    int k = 2;
    node *kLCA = kthLCA(root, 7, 6, k,ans);
    //      1
    //     2  3
    // 4   5  6  7
    if (kLCA == NULL)
        cout
            << "kthLCA doesn't exist" << endl;
    else
        cout << "kthLCA : " << ans;
    return 0;
}