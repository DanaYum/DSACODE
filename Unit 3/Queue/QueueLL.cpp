#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

void traversal(struct Node* ptr) {
    while (ptr != NULL) {
        cout << "Element in the queue: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

void enqueue(struct Node* &f, struct Node* &r, int val) {
    struct Node* n = new Node;
    if (n == NULL) {
        cout << "Queue is full.." << endl;
    } else {
        n->data = val;
        n->next = NULL;
        if (f == NULL) {
            f = r = n;
        } else {
            r->next = n;
            r = n;
        }
    }
}

int dequeue(struct Node* &f) {
    if (f == NULL) {
        cout << "Queue is empty.." << endl;
        return -1;  // Return a sentinel value indicating empty queue
    } else {
        struct Node* temp = f;
        int val = temp->data;
        f = f->next;
        delete temp;
        return val;
    }
}

int main() {
    struct Node* f = NULL;
    struct Node* r = NULL;
    enqueue(f, r, 10);
    enqueue(f, r, 42);
    enqueue(f, r, 90);
    enqueue(f, r, 76);

    cout << "Queue elements:" << endl;
    traversal(f);

    cout << "Dequeued element: " << dequeue(f) << endl;

    return 0;
}
