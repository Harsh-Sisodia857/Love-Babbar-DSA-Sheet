#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int size, int idx)
{
    int largest = idx;
    int left = 2 * idx;
    int right = 2 * idx + 1;
    if (left <= size && (arr[largest] < arr[left]))
    {
        largest = left;
    }
    if (right <= size && (arr[largest] < arr[right]))
    {
        largest = right;
    }
    if (largest != idx)
    {
        swap(arr[largest], arr[idx]);
        heapify(arr, size, largest);
    }
}

void printArray(int arr[], int N)
{
    for (int i = 1; i <= N; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void heapSort(int arr[], int n)
{
    int size = n;
    // Build a max heap
    for (int i = n / 2; i >= 1; i--)
    {
        heapify(arr, n, i);
    }
    while (size > 1)
    {
        // Step 1 : swap first and last element in array
        swap(arr[1], arr[size]);
        // Step 2 : Decrease the size
        size--;
        // Step 3 : Heapify
        heapify(arr, size, 1);
    }
}

// Driver's code
int main()
{
    int arr[] = {-1, 12, 11, 13, 5, 6, 7};
    int N = sizeof(arr) / sizeof(arr[0]);
    N = N - 1;
    // Function call
    heapSort(arr, N);

    cout << "Sorted array of Size "<<N<< " is \n";
    printArray(arr, N);
}