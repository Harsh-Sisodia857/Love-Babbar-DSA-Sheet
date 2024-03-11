
// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Node of the binary tree
struct node
{
    int data;
    node *left;
    node *right;
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};


// Function to print flattened
// binary Tree
void print(node *parent)
{
    node *curr = parent;
    while (curr != NULL){
        cout << curr->data << "->";
        curr = curr->right;
    }
    cout << "NULL" << endl;
}

node* flatten(node *root){
    if(root == NULL)
        return NULL;
    node *curr = root;
    while(curr != NULL){
        if(curr->left == NULL){
            curr = curr->right;
        }
        else{
            node *prev = curr->left;
            while(prev->right){
                prev = prev->right;
            }
            prev->right = curr->right; 
            curr->right = curr->left;
            curr->left = NULL;
            curr = curr->right;
        }
    }
    return root;
}

int main()
{

    node *root = new node(5);
    root->left = new node(3);
    root->right = new node(7);
    root->left->left = new node(2);
    root->left->right = new node(4);
    root->right->left = new node(6);
    root->right->right = new node(8);

    // Calling required function
    print(flatten(root));

    return 0;
}