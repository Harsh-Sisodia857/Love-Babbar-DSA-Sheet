#include<bits/stdc++.h>
using namespace std;

vector<int> diagonal(Node *root)
{
    // your code here
    map<int, vector<int>> m;

    queue<pair<Node *, int>> q;
    q.push({root, 0});
    vector<int> ans;
    while (!q.empty())
    {
        auto firstEle = q.front();
        q.pop();
        Node *curr = firstEle.first;
        int hdis = firstEle.second;
        while (curr)
        {
            // printing all the nodes having same vertical distance
            ans.push_back(curr->data);
            if (curr->left)
                q.push({curr->left, hdis + 1});
            curr = curr->right;
        }
    }
    for (auto it = m.begin(); it != m.end(); ++it)
    {
        for (auto j : it->second)
            ans.push_back(j);
    }

    return ans;
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