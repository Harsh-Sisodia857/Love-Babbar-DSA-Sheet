// segment tree is just like a binary tree every node has 0,1,2 child. Segment tree is used when there are Q queries and out of them we have to perform updation and find the result within any range.
// If there are N leaf nodes then there are N - 1 internal nodes, so total nodes are : 2N - 1
// We start building the segment tree from idx 1 so we create tree array of size 2N, for 1 based indexing left child is present at (2*currentIdx) and right child is present at (2*currentIdx + 1)
// updation in segment tree is O(logn)
// finding within any range like sum or product according to question is O(logn)
// Creating Segment Tree will Take O(logn) as height of tree is logn and we traverse maximum till the height of the tree


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

int main(){
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int *tree = new int[18];
  buildTree(arr, tree, 0, 8, 1);

  // printing the segment tree
  for (int i = 1; i < 18; i++){
    cout << tree[i] << " ";
  }
    return 0;
}