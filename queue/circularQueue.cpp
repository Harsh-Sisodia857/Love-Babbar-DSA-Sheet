// C or C++ program for insertion and
// deletion in Circular Queue
#include <bits/stdc++.h>
using namespace std;

class Queue
{
    // Initialize front and rear
    int rear, front;

    // Circular Queue
    int size;
    int *arr;

public:
    Queue(int s)
    {
        front = rear = -1;
        size = s;
        arr = new int[s];
    }

    void enQueue(int value);
    int deQueue();
    void displayQueue();
};

/* Function to create Circular queue */
void Queue::enQueue(int value)
{
    if ((rear + 1) % size == front)
    {
        printf("\nQueue is Full");
        return;
    }
    // queue is empty
   if(front == -1){
        front = 0;
        rear = 0;
        arr[rear] = value;
        return;
   }
   rear = (rear + 1) % size;
   arr[rear] = value;
}

// Function to delete element from Circular Queue
int Queue::deQueue()
{
   if(front == -1){
        cout << "Queue is empty" << endl;
        return -1;
   }
    int data = arr[front];
    arr[front] = -1;
    if(front == rear){
        front = -1;
        rear = -1;
        return data;
    }
   front = (front + 1) % size;
   return data;
}

// Function displaying the elements
// of Circular Queue
void Queue::displayQueue()
{
   int temp = front;
   while(temp != rear){
        cout << arr[temp] << " ";
        temp = (temp + 1) % size;
   }
   cout << arr[rear];
}

/* Driver of the program */
int main()
{
    Queue q(5);

    // Inserting elements in Circular Queue
    q.enQueue(14);
    q.enQueue(22);
    q.enQueue(13);
    q.enQueue(-6);

    // Display elements present in Circular Queue
    q.displayQueue();

    // Deleting elements from Circular Queue
    printf("\nDeleted value = %d", q.deQueue());
    printf("\nDeleted value = %d", q.deQueue());
    cout << endl;

    q.displayQueue();

    q.enQueue(9);
    q.enQueue(20);
    q.enQueue(5);

    q.displayQueue();

    q.enQueue(20);
    return 0;
}
