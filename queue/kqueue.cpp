#include<bits/stdc++.h>
using namespace std;

class kQueue{
    public : 
    int n;
    int k;
    int *arr;
    int *nextIdx;
    int *front;
    int *rear;
    int freeSpot;
    kQueue(int size,int noOfQueue){
        n = size;
        k = noOfQueue;
        arr = new int[n];
        nextIdx = new int[n];
        for (int i = 0; i < n; i++){
            nextIdx[i] = i + 1;
        }
        nextIdx[n - 1] = -1;
        front = new int[k];
        rear = new int[k];
        for(int i = 0; i < n; i++){
            front[i] = -1;
            rear[i] = -1;
        }
        freeSpot = 0;
    }

    void push(int value,int qn){

        // check for overflow
        if(freeSpot == -1){
            cout << "NO SPACE AVAILABLE" << endl;
            return;
        }

        // getting index where we have to push the element
        int idx = freeSpot;
        // updating freeSpot
        freeSpot = nextIdx[idx];

        // the pushing value is first element in the queue
        if(front[qn-1] == -1){
            // updating front array
            front[qn - 1] = idx;
        }else{
            // updating nextIdx array
            nextIdx[rear[qn-1]] = idx;
        }
        // nextIdx of current queue's element is -1
        nextIdx[idx] = -1;
        rear[qn - 1] = idx;
        // pushing the element
        arr[idx] = value;
    }

    int dequeue(int qn){
        // underflow
        if(front[qn-1] == -1){
            cout << "NO ELEMENT IN QUEUE" << endl;
            return -1;
        }
        // find the index of front
        int idx = front[qn - 1];
        // front ko aage bhadao
        front[qn - 1] = nextIdx[idx];
        // managing freeSpot
        nextIdx[idx] = freeSpot;
        freeSpot = idx;
        // returning poped element
        return arr[idx];
    }
};



int main(){
    kQueue q(10, 3);
    q.push(20, 1);
    q.push(2, 1);
    q.push(10, 1);
    q.push(30, 1);
    q.push(6, 2);
    q.push(16, 2);
    q.push(89, 2);
    cout << q.dequeue(1) << " ";
    cout << q.dequeue(2) << " ";
    cout << q.dequeue(1) << " ";
    cout << q.dequeue(1) << " ";
    cout << q.dequeue(1) << " ";
    return 0;
  }