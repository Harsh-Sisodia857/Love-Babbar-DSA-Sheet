#include<bits/stdc++.h>
using namespace std;

void buildTree(int *arr,int *tree,int start,int end,int idx){
    if(start == end){
        tree[idx] = arr[start];
        return;
    }

    int mid = (start + end) / 2;
    buildTree(arr, tree, start, mid, 2*idx);
    buildTree(arr, tree, mid + 1, end, 2*idx+1);
    tree[idx] = tree[2 * idx] + tree[2 * idx + 1];
}

void updateSegmentTree(int *arr,int *tree,int start,int end,int treeIdx,int idx,int value){
    if(start == end){
        arr[idx] = value;
        tree[treeIdx] = value;
        return;
    }

    int mid = (start + end) / 2;
    if(mid > idx){
        updateSegmentTree(arr, tree, start, mid, 2 * treeIdx, idx, value);
    }else{
        updateSegmentTree(arr, tree, mid + 1, end, 2 * treeIdx + 1, idx, value);
    }
    tree[treeIdx] = tree[2*treeIdx] + tree[2*treeIdx + 1];
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int *tree = new int[5];
    buildTree(arr, tree, 0, 4, 1);

    // printing the segment tree before updation
    for (int i = 1; i < 10; i++)
    {
        cout << tree[i] << " ";
    }
    cout << endl;
    updateSegmentTree(arr,tree,0,4,1,2,15);

    for (int i = 1; i < 10; i++)
    {
        cout << tree[i] << " ";
    }
    return 0;
}