//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Utility function to create a new Tree Node
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

void inorderTraversal(Node *root)
{
    if (root)
    {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

// } Driver Code Ends
// User function Template for C++

/*struct Node
{
    int data;
    Node* left;
    Node* right;
};*/
class Solution
{
public:
    void removeNodes(Node *root, int l, int r, vector<int> &toDeleted)
    {
        if (root)
        {
            removeNodes(root->left, l, r, toDeleted);
            if (root->data < l || root->data > r)
            {
                toDeleted.push_back(root->data);
            }
            removeNodes(root->right, l, r, toDeleted);
        }
    }

    Node *minValNode(Node *root)
    {
        Node *current = root;
        while (current->left != NULL)
        {
            current = current->left;
        }
        return current;
    }

    Node *deletingNode(Node *&root, int key)
    {
        if (root == NULL)
            return NULL;

        if (root->data > key)
        {
            root->left = deletingNode(root->left, key);
        }
        else if (root->data < key)
        {
            root->right = deletingNode(root->right, key);
        }
        else
        {
            if (root->left == NULL && root->right == NULL)
            {
                cout << root->data << endl;
                return NULL;
            }
            else if (root->left == NULL)
            {
                Node *temp = root->right;
                return temp;
            }
            else if (root->right == NULL)
            {
                Node *temp = root->left;
                return temp;
            }
            else
            {
                Node *temp = minValNode(root->right);
                root->data = temp->data;
                root->right = deletingNode(root->right, temp->data);
            }
        }
        return root;
    }

    Node *removekeys(Node *root, int l, int r)
    {
        vector<int> toDeleted;
        removeNodes(root, l, r, toDeleted);
        for (auto it : toDeleted)
        {
            deletingNode(root, it);
        }
        return root;
    }
};

//{ Driver Code Starts.
/* Driver program to test size function*/
int main()
{

    int t;
    cin >> t;
    getchar();
    while (t--)
    {
        int l, r;
        cin >> l >> r;

        string ln;
        getline(cin, ln);

        string inp, ch;
        getline(cin, inp);
        struct Node *root = buildTree(inp);
        Solution obj;
        Node *head = obj.removekeys(root, l, r);

        inorderTraversal(head);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends