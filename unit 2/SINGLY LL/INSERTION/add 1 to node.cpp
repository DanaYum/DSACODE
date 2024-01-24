#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to create a linked list based on user input
Node* createLinkedList() {
    int n;
    cin >> n;
    Node* head = nullptr;
    Node* current = nullptr;

    for (int i = 0; i < n; i++) {
        Node* newNode = new Node;
        cin >> newNode->data;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            current = newNode;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }

    return head;
}

// Function to add 1 to the barcode value and update the linked list
Node* addOneToBarcode(Node* head) {
    Node* current = head;
    Node* lastNonNine = nullptr;

    // Traverse the linked list to find the rightmost non-nine digit
    while (current != nullptr) {
        if (current->data != 9) {
            lastNonNine = current;
        }
        current = current->next;
    }

    // Increment the rightmost non-nine digit by 1
    if (lastNonNine == nullptr) {
        // If all digits are 9, create a new node with data 1
        Node* newNode = new Node;
        newNode->data = 1;
        newNode->next = head;
        head = newNode;
    } else {
        lastNonNine->data++;
        current = lastNonNine->next;

        // Set all digits to the right of the rightmost non-nine digit to 0
        while (current != nullptr) {
            current->data = 0;
            current = current->next;
        }
    }

    return head;
}

// Function to print the linked list
void printLinkedList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* head = createLinkedList();
    head = addOneToBarcode(head);
    printLinkedList(head);

    // Free the memory allocated for the linked list nodes
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
