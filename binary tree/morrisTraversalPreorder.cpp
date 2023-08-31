#include <bits/stdc++.h>
using namespace std;

/* A binary tree Node has data, a pointer to left child
and a pointer to right child */
class Node
{
    public : 
        int data;
        Node *left;
        Node *right;
        Node(int val){
            left = NULL;
            right = NULL;
            data = val;
        }
};

/* Function to traverse the binary tree without recursion
and without stack */
void MorrisTraversal(Node *root)
{
    if(root == NULL)
        return;

    vector<int> preorder;
    Node *curr = root;
    while(curr != NULL){
        if(curr->left == NULL){
            preorder.push_back(curr->data);
            curr = curr->right;
        }
        else{
            Node *prev = curr->left;
            while(prev->right && prev->right != curr){
                prev = prev->right;
            }
            if(prev->right == NULL){
                prev->right = curr;
                preorder.push_back(curr->data);
                curr = curr->left;
            }
            else{
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }
    cout << "\nPREORDER SIZE : " << preorder.size() << endl;
    for(auto it : preorder)
        cout << it << " ";
}


/* Driver program to test above functions*/
int main()
{

    /* Constructed binary tree is
            1
        / \
        2	 3
    / \
    4	 5
*/
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    MorrisTraversal(root);

    return 0;
}
