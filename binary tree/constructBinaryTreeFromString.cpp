#include <bits/stdc++.h>
using namespace std;

// custom data type for tree building
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

void preorder(Node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

Node* createNode(int p){
    Node *temp = new Node(p);
    return temp;
}

int findIndex(string s,int st,int e){
    for (int i = st; i <= e; i++)
        if(s[i] == ')')
            return i;
    return -1;
}

Node *constructtree(string s, int *start,int *end){
    if(*start > *end)
        return NULL;
    int num = 0;
    while (*start <= *end && s[*start] >= '0' && s[*start] <= '9'){
        num *= 10;
        num += (s[*start] - '0');
        (*start)++;
    }
    Node *root = createNode(num);
    int index = -1;
    if(s[*start] == '(' && *start <= *end){
        index = findIndex(s, *start, *end);
    }
    if(index == -1)
        return NULL;
    root->left = constructtree(s, &(*start+1), &(index-1));
    root->right = constructtree(s, &(index + 2),&(*end));
    return root;
}
    int main()
{
    string s = "4(2(3)(1))(6(5))";
    // cin>>s;
    int start = 0;
    int end = s.length() - 1;
    Node *root = constructtree(s, &start,&end);
    preorder(root);
    return 0;
}