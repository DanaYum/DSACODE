#include <iostream>
using namespace std;

// Define the structure for a node
struct Node {
    int value;
    Node* next;

   Node(int val) : value(val), next(nullptr) {}
};

// Function to insert a new node in sorted order
void insertSorted(Node*& head, int val) {
    Node* newNode = new Node(val);
    
    if (!head || val < head->value) {
        newNode->next = head;
        head = newNode;
        return;
    }
    
    Node* current = head;
    while (current->next && val > current->next->value) {
        current = current->next;
    }
    
    newNode->next = current->next;
    current->next = newNode;
}

// Function to print the linked list
void printList(Node* head) {
    Node* current = head;
    while (current) {
        cout << current->value;
        current = current->next;
    }
}

int main() {
    int n;
    cin >> n;
    
    Node* sortedList = nullptr;
    
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        insertSorted(sortedList, val);
    }
    
    int newVal;
    cin >> newVal;
    insertSorted(sortedList, newVal);
    
    printList(sortedList);
    
    // Clean up memory (free the nodes)
    Node* current = sortedList;
    while (current) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    
    return 0;
}
