#include<bits/stdc++.h>
using namespace std;

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int l, int r)
{
    int pivotElement = arr[r];
    int i = l-1;
    int j = l;
    for (j = l; j < r; j++){
        if (arr[j] < pivotElement)
        {
            i++;
            swap(arr,i,j);
        }
    }
    swap(arr,i+1, r);
    return i+1;
}

void quickSort(int arr[],int l,int r){
    if(l < r){
        int pi = partition(arr, l, r);
        quickSort(arr, l, pi - 1);
        quickSort(arr, pi + 1, r);
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {2, 3, 25, 11, 42, 13, 15};
    int s = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, s - 1);
    for (int i = 0; i < s; i++)
        cout << arr[i] << " ";
    return 0;
}