#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};
void diagonalPrint(Node *root){
    if(root == NULL)
        return;
    map<int, vector<int>> m;
    queue<pair<Node *,int>> q;
    q.push({root,0});
    while(!q.empty()){
        Node *temp = q.front().first;
        int hdis = q.front().second;
        q.pop();
        if(temp != NULL){
        m[hdis].push_back(temp->data);
        if(temp->left)
            q.push({temp->left,hdis-1});

        if(temp->right)
            q.push({temp->right,hdis});
        }
    }
    for(auto it : m){
        cout << it.first << " :";
        for(auto j : it.second)
            cout << j << " ";
        cout << endl;
    }
}

Node *newNode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

int main()
  {
      Node *root = newNode(8);
      root->left = newNode(3);
      root->right = newNode(10);
      root->left->left = newNode(1);
      root->left->right = newNode(6);
      root->right->right = newNode(14);
      root->right->right->left = newNode(13);
      root->left->right->left = newNode(4);
      root->left->right->right = newNode(7);
      diagonalPrint(root);

      return 0;
  }