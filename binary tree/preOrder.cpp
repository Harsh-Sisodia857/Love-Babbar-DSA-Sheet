#include <iostream>
#include <stack>
using namespace std;

// Data structure to store a binary tree node
struct Node
{
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

// Iterative function to perform inorder traversal on the tree
void preOrderIterative(Node *root)
{
    stack<Node*> st;
    Node *curr = root;
    st.push(curr);
    while(!st.empty()){
        Node* temp = st.top();
        st.pop();
        cout << temp->data << " ";
        if(temp->right)
            st.push(temp->right);
        if(temp->left)
            st.push(temp->left);
    }
}

void preorder(Node *root){
    if(root){
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    /* Construct the following tree
               1
             /   \
            /     \
           2       3
          /      /   \
         /      /     \
        4      5       6
              / \
             /   \
            7     8
    */

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);

    preOrderIterative(root);
    cout << "PREORDER : ";
    preorder(root);

    return 0;
}