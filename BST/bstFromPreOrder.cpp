// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
class node
{
public:
    int data;
    node *left;
    node *right;
};

// A utility function to create a node
node *newNode(int data)
{
    node *temp = new node();

    temp->data = data;
    temp->left = temp->right = NULL;

    return temp;
}

void printInorder(node *node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

node* constructTree(int pre[],int n,int *preorderIdx,int min,int max){
    if(*preorderIdx >= n)
        return NULL;
    if(pre[*preorderIdx] < min || pre[*preorderIdx] > max)
        return NULL;
    int key = pre[*preorderIdx];
    node *temp = newNode(key);
    *preorderIdx = *preorderIdx + 1;
    temp->left = constructTree(pre, n,preorderIdx , min, key);
    temp->right = constructTree(pre, n, preorderIdx, key,max);
    return temp;
}

int main(){
      int pre[] = {10, 5, 1, 7, 40, 50};
      int size = sizeof(pre) / sizeof(pre[0]);
      int preOrderIdx = 0;
      // Function call
      node *root = constructTree(pre, size,&preOrderIdx,INT_MIN,INT_MAX);

      printInorder(root);

      return 0;
      return 0;
  }