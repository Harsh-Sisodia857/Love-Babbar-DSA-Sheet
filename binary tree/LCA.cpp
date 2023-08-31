#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool getPath(node *root,int n1,vector<int> &path){
    if(root == NULL)
        return false;
    path.push_back(root->data);
    if(root->data == n1)
        return true;
    if(getPath(root->left, n1, path))
        return true;

    if(getPath(root->right, n1, path))
        return true;
    
    path.pop_back();
    return false;
}

// int LCA(node *root,int n1,int n2){
//     vector<int> path1, path2;
//     if(!getPath(root,n1,path1) || !getPath(root,n2,path2)){
//         return -1;
//     }
//     int i;
//     for (i = 0; i < path1.size() && path2.size(); i++){
//         if(path1[i] != path2[i])
//             break;
//     }
//     return path2[i - 1];
// }

node *lca(node *root, int n1, int n2)
{
    if (root == NULL)
        return NULL;
    if (root->data == n1 || root->data == n2)
        return root;
    node *left = lca(root->left, n1, n2);
    node *right = lca(root->right, n1, n2);
    if (left == NULL && right == NULL)
        return NULL;
    if(left && right)
        return root;
    if(!left)
        return right;
    return left;
}

int main()
  {
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    node* Lca = lca(root, 7, 6);
    //      1
    //     2  3
    // 4   5  6  7
    if (Lca == NULL)
        cout
            << "LCA doesn't exist" << endl;
    else
        cout << "LCA : " << Lca->data;
    return 0;
  }