  int idx = 0;
    Node* solve(int pre[], int size,int max){
        if(idx >= size || pre[idx] > max)
            return NULL;
        Node *root = newNode(pre[idx++]);
        root->left = solve(pre,size,root->data);
        root->right = solve(pre,size,max);
        return root;
    }
    Node* post_order(int pre[], int size)
    {
        return solve(pre,size,INT_MAX);
    }