//enter any no only +ve int, when compiler encounter -ve value the program will terminate
#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

// Function to insert a node at the end of the linked list
void insertAtEnd(struct Node*& head, int value) {
    struct Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        struct Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to print the linked list
void printLinkedList(struct Node* head) {
    if (head == nullptr) {
        cout << "Linked List is empty." << endl;
        return;
    }

    cout << "Linked List: ";
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    struct Node* head = nullptr;
    int value;

    cout << "Enter integer values to insert into the linked list (enter a negative value to terminate):" << endl;
    while (cin >> value && value >= 0) {
        insertAtEnd(head, value);
    }

    printLinkedList(head);

    return 0;
}
