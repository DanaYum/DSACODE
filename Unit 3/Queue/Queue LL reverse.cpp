#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int customerPosition) {
        Node* newNode = new Node();
        newNode->data = customerPosition;
        newNode->next = nullptr;

        if (rear == nullptr) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void displayQueueReverse() {
        if (front == nullptr) {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Queue: ";
        displayReverseHelper(front);
        cout << endl;
    }

private:
    void displayReverseHelper(Node* current) {
        if (current == nullptr)
            return;

        displayReverseHelper(current->next);
        cout << current->data << " ";
    }
};

int main() {
    int N;
    cout << "Enter the number of customers in the queue: ";
    cin >> N;

    Queue queue;

    if (N > 0) {
        cout << "Enter customer positions: ";
        for (int i = 0; i < N; ++i) {
            int position;
            cin >> position;
            queue.enqueue(position);
        }
    }

    queue.displayQueueReverse();

    return 0;
}
