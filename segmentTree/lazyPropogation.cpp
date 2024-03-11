#include <bits/stdc++.h>
using namespace std;

void buildTree(int *arr, int *tree, int start, int end, int treeIdx)
{
    if (start == end)
    {
        tree[treeIdx] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    buildTree(arr, tree, start, mid, 2 * treeIdx);
    buildTree(arr, tree, mid + 1, end, 2 * treeIdx + 1);
    tree[treeIdx] = min(tree[2 * treeIdx], tree[2 * treeIdx + 1]);
}

void updateSegmentTree(int *tree, int *lazy, int start, int end, int treeIdx, int startRange, int endRange, int inc)
{
    if (start > end)
        return;

    // before updating check lazy tree at current position
    if (lazy[treeIdx] != 0)
    {
        tree[treeIdx] += lazy[treeIdx];
        // if it is not the leaf node
        if (start != end)
        {
            lazy[2 * treeIdx] += lazy[treeIdx];
            lazy[2 * treeIdx + 1] += lazy[treeIdx];
        }
        lazy[treeIdx] = 0;
    }

    // complete overlapping
    if (startRange <= start && endRange >= end)
    {
        tree[treeIdx] += inc;
        if (start != end)
        {
            lazy[2 * treeIdx] += inc;
            lazy[2 * treeIdx + 1] += inc;
        }
        return;
    }

    // complete outside
    if (end < startRange || start > endRange)
        return;

    // partially overlapping
    int mid = (start + end) / 2;
    updateSegmentTree(tree, lazy, start, mid, 2 * treeIdx, startRange, endRange, inc);
    updateSegmentTree(tree, lazy, mid + 1, end, 2 * treeIdx + 1, startRange, endRange, inc);
    tree[treeIdx] = min(tree[2 * treeIdx], tree[2 * treeIdx + 1]);
}

int main()
{
    int arr[] = {1, 3, -2, 4};
    int *tree = new int[12];

    buildTree(arr, tree, 0, 3, 1);
    int *lazy = new int[12]();
    updateSegmentTree(tree, lazy, 0, 3, 1, 0, 3, 3);
    updateSegmentTree(tree, lazy, 0, 3, 1, 0, 1, 2);

    cout << "Segment Tree " << endl;
    for (int i = 1; i < 12; i++)
    {
        cout << tree[i] << " ";
    }
    cout << endl;

    cout << "Lazy Tree " << endl;
    for (int i = 1; i < 12; i++)
    {
        cout << lazy[i] << " ";
    }
    cout << endl;

    return 0;
}
