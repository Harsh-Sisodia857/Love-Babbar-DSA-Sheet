#include <bits/stdc++.h>
using namespace std;

/* A binary tree Node has data, a pointer to left child
and a pointer to right child */
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        left = NULL;
        right = NULL;
        data = val;
    }
};

Node* createNode(int val){
    Node *temp = new Node(val);
    return temp;
}

void printLinkedList(Node *head)
{
    if (head)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->right;
        }
        cout <<"NULL"<< endl;
    }
}



void MorrisTraversal(Node *root)
{
    if (root == NULL)
        return;

    vector<int> inorder;
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
    Node *head = NULL,*p = NULL;
    for (auto it : inorder){
        if(head == NULL){
            head = createNode(it);            
            p = head;
        }
        else{
            Node *temp = createNode(it);
            temp->left = p;
            p->right = temp;
            p = temp;
        }
    }
    printLinkedList(head);
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
