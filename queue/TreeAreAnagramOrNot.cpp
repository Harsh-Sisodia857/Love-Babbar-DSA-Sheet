/* Iterative program to check if two trees are level
by level anagram. */
#include <bits/stdc++.h>
using namespace std;

// A Binary Tree Node
struct Node
{
    struct Node *left, *right;
    int data;
};


bool areAnagrams(Node *root1, Node *root2)
{
    // Base Cases
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL || root2 == NULL)
        return false;
    vector<int> tree1, tree2;

    queue<Node*> q1, q2;
    q1.push(root1);
    q2.push(root2);
    while(1){
        int n1 = q1.size();
        int n2 = q2.size();
        if(n1 != n2)
            return false;
        // level order is completed
        if(n1 == 0)
            break;
        while(n1){
            Node *temp1 = q1.front();
            q1.pop();
            if(temp1->left)
                q1.push(temp1->left);
            if(temp1->right)
                q1.push(temp1->right);
            n1--;
            Node *temp2 = q2.front();
            q2.pop();
            if (temp2->left)
                q2.push(temp1->left);
            if (temp1->right)
                q2.push(temp1->right);
            tree1.push_back(temp1->data);
            tree2.push_back(temp2->data);
        }
        sort(tree1.begin(), tree1.end());
        sort(tree2.begin(), tree2.end());
        if(tree1 != tree2)
            return false;
    }
    return true;
}

// Utility function to create a new tree Node
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Driver program to test above functions
int main()
{
    // Constructing both the trees.
    struct Node *root1 = newNode(1);
    root1->left = newNode(3);
    root1->right = newNode(2);
    root1->right->left = newNode(5);
    root1->right->right = newNode(4);

    struct Node *root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5);

    areAnagrams(root1, root2) ? cout << "Yes": cout << "No";
    return 0;
}
