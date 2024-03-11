#include<bits/stdc++.h>
using namespace std;

void buildTree(int *arr,int *tree,int start,int end,int treeIdx){
    if(start == end){
        tree[treeIdx] = arr[start];
        return;
    }

    int mid = (start + end) / 2;
    buildTree(arr, tree, start, mid, 2 * treeIdx);
    buildTree(arr, tree, mid + 1, end, 2 * treeIdx + 1);
    tree[treeIdx] = tree[2 * treeIdx] + tree[2 * treeIdx + 1];
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
        updateSegmentTree(arr, tree, mid+1, end, 2 * treeIdx + 1, idx, value);
    }
    tree[treeIdx] = tree[2 * treeIdx] + tree[2 * treeIdx + 1];
}

int findRange(int *tree,int start,int end,int treeIdx,int left,int right){
    // completely outside the range 
    if(end < left || start > right){
        return 0;
    }
    // completely within the range
    if(start >= left && end <= right){
        return tree[treeIdx];
    }
    // partially in the range
    int mid = (start + end) / 2;
    int ans1 = findRange(tree, start, mid, 2*treeIdx, left, right);
    int ans2 = findRange(tree, mid + 1, end, 2 * treeIdx + 1, left, right);
    return ans1 + ans2;
}

int main(){
    int arr[] = {1, 2, 3, 4, 5};
    int *tree = new int[10];
    buildTree(arr, tree, 0, 4, 1);

    // printing the segment tree before updation
    for (int i = 1; i < 10; i++)
    {
        cout << tree[i] << " ";
    }
    cout << endl;
    updateSegmentTree(arr, tree, 0, 4, 1, 2, 15);

    cout << "After updating : ";
    for (int i = 1; i < 10; i++)
    {
        cout << tree[i] << " ";
    }

    // find sum from the range 2 to 4
    int ans = findRange(tree, 0, 4, 1, 2, 4);
    cout << endl<<"Range from 2 to 4 is : "<< ans;
    return 0;
}