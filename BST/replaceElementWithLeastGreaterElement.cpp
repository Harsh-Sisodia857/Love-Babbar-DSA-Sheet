//   vector<int> findLeastGreater(vector<int>& arr, int n) {
//         vector<int> ans;
//         set<int> s;
//         for(int i = n-1; i >= 0; i--){
//             s.insert(arr[i]);
//             if(s.upper_bound(arr[i]) != s.end())
//                 ans.push_back(*s.upper_bound(arr[i]));
//             else
//                 ans.push_back(-1);
//         }
//         reverse(ans.begin(),ans.end());
//         return ans;
//     }

// least greater element on its right

#include <bits/stdc++.h>
using namespace std;

// A binary Tree node
struct Node
{
    int data;
    Node *left, *right;
};

// A utility function to create a new BST node
Node *newNode(int item)
{
    Node *temp = new Node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

/* A utility function to insert a new node with
given data in BST and find its successor */
Node *insert(Node *root, int val, int &suc)
{
    /* If the tree is empty, return a new node */
    if (!root)
        return newNode(val);
    // go to right subtree
    if (val >= root->data)
        root->right = insert(root->right, val, suc);
    // If key is smaller than root's key, go to left
    // subtree and set successor as current node
    else
    {
        suc = root->data;
        root->left = insert(root->left, val, suc);
    }
    return root;
}

// Function to replace every element with the
// least greater element on its right
void replace(int arr[], int n)
{
    Node *root = nullptr;
    // start from right to left
    for (int i = n - 1; i >= 0; i--)
    {
        int suc = -1;
        // insert current element into BST and
        // find its inorder successor
        root = insert(root, arr[i], suc);
        // cout << suc << " " << endl;
        arr[i] = suc;
    }
}

// Driver Program to test above functions
int main()
{
    int arr[] = {8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28};
    // answer -  18 63 80 25 32 43 80 93 80 25 93 -1 28 -1 -1
    // for a node to be inserted the least left node is its inorder successor
    int n = sizeof(arr) / sizeof(arr[0]);
    replace(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
