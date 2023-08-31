#include<bits/stdc++.h>
using namespace std;

class Myqueue{
    int *arr;
    int n;
    int front;
    int rear;
    public : 
    Myqueue(int size){
        n = size;
        arr = new int[n];
        front = -1;
        rear = -1;
    }
    void enqueue(int x){
        if(rear == n-1){
            cout << "Overflow" << endl;
            return;
        }
        rear++;
        arr[rear] = x;
        if(front == -1)
            front++;
    }
    void dequeue(){
        if(front == -1 || front > rear){
            cout << "Underflow" << endl;
            return;
        }
        front++;
    }
    int peek(){
        if(front == -1 || front > rear){
            cout << "Underflow" << endl;
            return -1;
        }
        return arr[front];
    }
    bool empty(){
        if(front == -1)
            return true;
        return false;
    }
};

int main(){
    Myqueue q(5);
    q.enqueue(3);
    q.enqueue(12);
    q.enqueue(30);
    q.enqueue(5);
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek() << endl;
    q.dequeue();
    cout << q.peek() << endl;
    return 0;
  }