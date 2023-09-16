//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};
// custom comparator
class cmp
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

class Solution
{
public:
    void traverse(Node *root, vector<string> &ans, string s)
    {
        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(s);
            return;
        }
        traverse(root->left, ans, s + '0');
        traverse(root->right, ans, s + '1');
    }
    vector<string> huffmanCodes(string S, vector<int> f, int N)
    {
        priority_queue<Node *, vector<Node *>, cmp> pq;
        for (int i = 0; i < N; i++)
        {
            Node *temp = new Node(f[i]);
            pq.push(temp);
        }
        // building huffman tree
        while (pq.size() > 1)
        {
            Node *left = pq.top();
            pq.pop();

            Node *right = pq.top();
            pq.pop();

            Node *newNode = new Node(left->data + right->data);
            pq.push(newNode);
            newNode->left = left;
            newNode->right = right;
        }
        // when last node is present in the heap it is the root node
        Node *root = pq.top();
        vector<string> ans;
        traverse(root, ans, "");
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string S;
        cin >> S;
        int N = S.length();
        vector<int> f(N);
        for (int i = 0; i < N; i++)
        {
            cin >> f[i];
        }
        Solution ob;
        vector<string> ans = ob.huffmanCodes(S, f, N);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends