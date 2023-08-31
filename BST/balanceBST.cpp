#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node *newNode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

/* Function to do preorder traversal of tree */
void preOrder(Node *node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

void getInorder(Node *root,vector<Node*> &inorder){
    if(root){
        getInorder(root->left, inorder);
        inorder.push_back(root);
        getInorder(root->right, inorder);
    }
}

Node* buildBalancedTree(vector<Node*> &inorder,int start,int end){
    if(start > end)
        return NULL;
    int mid = (start + end) / 2;
    Node *root = newNode(inorder[mid]->data);
    root->left = buildBalancedTree(inorder, start, mid - 1);
    root->right = buildBalancedTree(inorder, mid+1,end);
    return root;
}

Node *buildTree(Node *root){
    // getting inorder of tree
    vector<Node*> inorder;
    getInorder(root, inorder);
    // building tree from inorder
    int n = inorder.size();
    Node * temp = buildBalancedTree(inorder, 0, n - 1);
    return temp;
}

    // Driver program
    int
    main()
{
    /* Constructed skewed binary tree is
                10
               /
              8
             /
            7
           /
          6
         /
        5   */

    Node *root = newNode(10);
    root->left = newNode(8);
    root->left->left = newNode(7);
    root->left->left->left = newNode(6);
    root->left->left->left->left = newNode(5);
    // building balanced tree
    root = buildTree(root);

    printf("Preorder traversal of balanced "
           "BST is : \n");
    preOrder(root);

    return 0;
}