#include<bits/stdc++.h>
using namespace std;

struct node{
    int maxi;
    int smaxi;
};


void buildTree(int *arr,node *tree,int start,int end,int treeIdx){
    if(start == end){
        tree[treeIdx].maxi = arr[start];
        tree[treeIdx].smaxi = INT_MIN;
        return;
    }

    int mid = (start + end) / 2;
    buildTree(arr, tree, start, mid, 2 * treeIdx);
    buildTree(arr, tree, mid + 1, end, 2 * treeIdx + 1);

    node left = tree[2 * treeIdx];
    node right = tree[2 * treeIdx + 1];
    tree[treeIdx].maxi = max(left.maxi, right.maxi);
    tree[treeIdx].smaxi = min(max(left.maxi, right.smaxi), max(right.maxi, left.smaxi));
    return;
}

node* findPair(node* tree,int start,int end,int treeIdx,int left,int right){
    // completely within the range
    if(start >= left && right >= end){
        return &tree[treeIdx];
    }
    // completely outside the range
    if(right < start || left > end){
        node *result = new node{INT_MIN, INT_MAX};
        return result;
    }
    // partially inside the range
    int mid = (start + end) / 2;
    auto leftNode = findPair(tree, start, mid, 2*treeIdx, left, right);
    auto rightNode = findPair(tree, mid + 1, end, 2*treeIdx + 1, left, right);
    int maximum = max(leftNode->maxi, rightNode->maxi);
    int secondMaxi = min(max(leftNode->maxi, rightNode->smaxi), max(rightNode->maxi, leftNode->smaxi));
    node *result = new node{maximum, secondMaxi};
    return result;
}

void updateSegmentTree(node *tree,int *arr,int start,int end,int treeIdx,int idx,int value){

    if(start == end){
        arr[idx] = value;
        tree[treeIdx].maxi = value;
        return;
    }

    int mid = (start + end) / 2;
    if(mid > idx){
        updateSegmentTree(tree, arr, start, mid, 2 * treeIdx, idx, value);
    }else{
        updateSegmentTree(tree, arr, mid + 1, end, 2*treeIdx+1, idx, value);
    }
    auto left = tree[2 * treeIdx];
    auto right = tree[2 * treeIdx + 1];
    tree[treeIdx].maxi = max(left.maxi,right.maxi);
    tree[treeIdx].smaxi = min(max(left.maxi, right.smaxi), max(right.maxi, left.smaxi));
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    node *tree = new node[4 * n];
    buildTree(arr, tree, 0, 4, 1);
    // for (int i = 1; i < 4 * n; i++)
    //     cout << tree[i].maxi << " " << tree[i].smaxi << endl;
    int t;
    cin >> t;
    while(t--){
        char operation;
        cin >> operation;
        
        if(operation == 'Q'){
            int left, right;
            cin >> left >> right;
            node *temp = findPair(tree, 0, 4, 1, left-1, right-1);
            cout << temp->maxi << " " << temp->smaxi << endl;
        }else if(operation == 'U'){
            int idx, value;
            cin >> idx >> value;
            updateSegmentTree(tree, arr, 0, 4, 1, idx, value);
        }else{
            cout << "Enter valid operation" << endl;
        }
    }

    return 0;
}