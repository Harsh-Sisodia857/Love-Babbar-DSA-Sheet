#include<bits/stdc++.h>
using namespace std;

class node{
    public : 
    int data;
    node *left;
    node *right;
    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

node* createNode(int val){
    node *temp = new node(val);
    return temp;
}


void getMirror(node *root,node **mirror){
    if(root == NULL){
        mirror = NULL;
        return;
    }
    *mirror = createNode(root->data);
    getMirror(root->left,&((*mirror)->right));
    getMirror(root->right,&((*mirror)->left));
    return;
}

void getInorder(node *root){
    if(root){
        getInorder(root->left);
        cout << root->data << " ";
        getInorder(root->right);
    }
}

int main(){
    node *root = new node(5);
    root->left = createNode(6);
    root->right = createNode(16);
    root->left->left = createNode(26);
    root->left->right = createNode(56);
    root->right->right = createNode(10);
    getInorder(root);
    cout << endl;
    node* mirrorRoot;
    getMirror(root, &mirrorRoot);
    getInorder(mirrorRoot);
    return 0;
  }