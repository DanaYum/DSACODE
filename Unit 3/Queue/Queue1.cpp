#include <iostream>
#include <cstdlib> // for exit()
#include <limits>  // for numeric_limits
#define MAX 5

using namespace std;

class Queue {
    int q[MAX];
    int front, rear;

    public:
    Queue() {
        rear = front = -1;
    }
    void enqueue(int x);
    int dequeue();
    bool isEmpty();
    bool isFull();
    int getFront();
};

int Queue::getFront() {
    if (front == rear) {
        cout << "Queue is underflow" << endl;
        return -1;
    } else {
        return q[front + 1];
    }
}

int Queue::dequeue() {
    int t;
    if (front == rear) {
        cout << "Queue is underflow" << endl;
        return -1;
    } else {
        front++;
        t= q[front];
    }
    return t;
}

void Queue::enqueue(int x) {
    if (rear == MAX - 1)
        cout << "Queue is full" << endl;
    else {
        rear++;
        q[rear] = x;
    }
}

int main() {
    Queue qq;
    // int x;
    // cout << "Enter elements to insert into the queue (Ctrl+D to stop):" << endl;
    // while (cin >> x) {
    //     qq.enqueue(x);
    // }
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int element;
        cin>>element;
        qq.enqueue(element);
    }

    cout << "dequeued element: " << qq.dequeue() << endl;
    cout << "dequeued element: " << qq.dequeue() << endl;

    return 0;
}
