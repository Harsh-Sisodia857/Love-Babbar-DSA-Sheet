#include<bits/stdc++.h>
using namespace std;

class heap{
    public : 
    int size;
    int arr[100];

    heap(){
        size = 0;
        arr[0] = -1;
    }
    void insert(int val){
        size = size + 1;
        int idx = size;
        arr[idx] = val;                                        
        while(idx > 1){                          
            int parent = idx / 2;                                  
            if(arr[parent] < arr[idx]){
                swap(arr[parent], arr[idx]);
                idx = parent;
            }else{
                return;
            }
        }
    }

    void deleteFromHeap(){
        if(size == 0){
            cout << "No element to delete" << endl;
            return;
        }
        // Step 1 : swap last element with root element
        arr[1] = arr[size];
        // Step 2 : decrease size
        size--;
        // Step 3 : Heapify
        // int idx = 1;
        // while (2 * idx <= size)
        // {
        //     int left = 2 * idx;
        //     int right = 2 * idx + 1;
        //     int largest = idx;
        //     if (left <= size && arr[left] > arr[largest])
        //     {
        //         largest = left;
        //     }
        //     if (right <= size && arr[right] > arr[largest])
        //     {
        //         largest = right;
        //     }

        //     if (largest != idx)
        //     {
        //         swap(arr[idx], arr[largest]);
        //         idx = largest;
        //     }
        //     else
        //     {
        //         break;
        //     }
        // }
        heapify(1);
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";              
        }
        cout << endl;
    }
    void heapify(int idx){
        int largest = idx;
        int left = 2 * idx;
        int right = 2 * idx + 1;
        if(left <= size && (arr[largest] < arr[left])){
            largest = left;
        }
        if(right <= size && (arr[largest] < arr[right])){
            largest = right;
        }
        if(largest != idx){
            swap(arr[largest], arr[idx]);          
            heapify(largest);
        }
    }
};

int main()
  {
    heap h;
    h.insert(12);
    h.insert(16);
    h.insert(18);
    h.insert(1);
    h.print();
    h.deleteFromHeap();
    h.print();
    h.deleteFromHeap();
    h.print();

    return 0;
  }