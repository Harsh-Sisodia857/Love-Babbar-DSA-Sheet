#include<bits/stdc++.h>
using namespace std;

struct node{
    int maxiSum;
    int sum;
    int bestPrefixSum;
    int bestSuffixSum;
};

void buildTree(int *arr,node *tree,int start,int end,int treeIdx){
    if(start == end){
        tree[treeIdx].sum = arr[start];
        tree[treeIdx].maxiSum = arr[start];
        tree[treeIdx].bestPrefixSum = arr[start];
        tree[treeIdx].bestSuffixSum = arr[start];
        return;
    }

    int mid = (start + end) / 2;
    buildTree(arr, tree, start, mid, 2 * treeIdx);
    buildTree(arr, tree, mid + 1, end, 2 * treeIdx + 1);

    node left = tree[2 * treeIdx];
    node right = tree[2 * treeIdx + 1];
    tree[treeIdx].sum = left.sum + right.sum;
    tree[treeIdx].maxiSum = max(left.maxiSum, right.maxiSum);
    tree[treeIdx].bestPrefixSum = left.bestPrefixSum;
    tree[treeIdx].bestSuffixSum = right.bestSuffixSum;
}

void updateSegmentTree(int *arr, node *tree, int start, int end, int treeIdx, int idx, int value)
{
    if (start == end)
    {
        arr[idx] = value;
        tree[treeIdx].sum = value;
        tree[treeIdx].maxiSum = value;
        tree[treeIdx].bestPrefixSum = value;
        tree[treeIdx].bestSuffixSum = value;
        return;
    }

    int mid = (start + end) / 2;
    if (mid >= idx)
    {
        updateSegmentTree(arr, tree, start, mid, 2 * treeIdx, idx, value);
    }
    else
    {
        updateSegmentTree(arr, tree, mid + 1, end, 2 * treeIdx + 1, idx, value);
    }

    node left = tree[2 * treeIdx];
    node right = tree[2 * treeIdx + 1];
    tree[treeIdx].sum = left.sum + right.sum;
    tree[treeIdx].maxiSum = max({left.maxiSum, right.maxiSum, left.bestSuffixSum + right.bestPrefixSum});
    tree[treeIdx].bestPrefixSum = max(left.bestPrefixSum, left.sum + right.bestPrefixSum);
    tree[treeIdx].bestSuffixSum = max(right.bestSuffixSum, right.sum + left.bestSuffixSum);
}

node *findPair(node *tree, int start, int end, int treeIdx, int left, int right)
{
    // completely inside
    if (start >= left && right >= end)
    {
        return &tree[treeIdx];
    }
    // completely outside
    if (right < start || end < left)
    {
        return new node{0, 0, 0, 0};
    }
    // partially inside and outside
    int mid = (start + end) / 2;
    node *leftNode = findPair(tree, start, mid, 2 * treeIdx, left, right);
    node *rightNode = findPair(tree, mid + 1, end, 2 * treeIdx + 1, left, right);

    int totalSum = leftNode->sum + rightNode->sum;
    int maxiSum = max({leftNode->maxiSum, rightNode->maxiSum, leftNode->bestSuffixSum + rightNode->bestPrefixSum});
    int leftSomeRight = max(leftNode->sum + rightNode->bestPrefixSum, leftNode->bestPrefixSum);
    int rightSomeLeft = max(rightNode->sum + leftNode->bestSuffixSum, rightNode->bestSuffixSum);

    return new node{maxiSum, totalSum, leftSomeRight, rightSomeLeft};
}

int main(){

    int arr[] = {14, 16, 3, 4, 25, 6};
    node *tree = new node[4 * 6];
    buildTree(arr, tree, 0, 5, 1);

    int t;
    cin >> t;
    while (t--)
    {
        char operation;
        cin >> operation;

        if (operation == 'Q')
        {
            int left, right;
            cin >> left >> right;
            node *temp = findPair(tree, 0, 4, 1, left - 1, right - 1);
            int ans = max({temp->sum, temp->maxiSum, temp->bestPrefixSum, temp->bestSuffixSum});
            cout << ans << " ";
        }
        else if (operation == 'U')
        {
            int idx, value;
            cin >> idx >> value;
            updateSegmentTree(arr, tree, 0, 4, 1, idx, value);
        }
        else
        {
            cout << "Enter valid operation" << endl;
        }
    }

    return 0;
}