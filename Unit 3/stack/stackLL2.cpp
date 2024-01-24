#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

void LLtraversal(struct Node* ptr) {
    while (ptr != NULL) {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

int isEmpty(struct Node* top) {
    if (top == NULL)
        return 1;
    else
        return 0;
}

int isFull(struct Node* top) {
    struct Node* p = new Node;
    if (p == NULL)//which means memory allocation is failed so it is full
        return 1;
    else
        return 0;
}

void push(struct Node* &top, int x) {
    struct Node* n = new Node;
    if (n == NULL) {
        cout << "Stack is overflow...\n";
        return;
    }
    n->data = x;
    n->next = top;
    top = n;
}
int pop(struct Node* &top) {
    if (isEmpty(top)) {
        cout << "Stack is underflow..." << endl;
        return -1;  // Return a sentinel value indicating underflow
    } else {
        struct Node* temp = top 
        int t = temp->data;
        top = top->next;
        delete temp;  // Free the memory of the popped node
        return t;
    }
}


int main() {
    struct Node* top = NULL;
    push(top, 24);
    push(top, 76);
    push(top, 97);
    cout<<"popped element is: "<<pop(top)<<endl;
    LLtraversal(top);
    return 0;
}
