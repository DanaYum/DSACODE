// You are using GCC
#include <iostream>
using namespace std;

// Define a structure for the linked list node
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// Create a class for the circular header linked list
class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList() : head(nullptr) {}

    // Method to insert a new element at the end
    void insertEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            newNode->next = head; // Make it circular
        } else {
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }
            current->next = newNode;
            newNode->next = head; // Make it circular
        }
    }

    // Method to check if the circular linked list is sorted in non-decreasing order
    bool isSorted() {
        if (!head) {
            return true; // Empty list is considered sorted
        }

        Node* current = head;
        do {
            if (current->data > current->next->data) {
                return false; // Found a decreasing element
            }
            current = current->next;
        } while (current->next != head);

        return true; // All elements are in non-decreasing order
    }
};

int main() {
    CircularLinkedList cll;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        cll.insertEnd(value);
    }

    if (cll.isSorted()) {
        cout << "The list is sorted in non-decreasing order." << endl;
    } else {
        cout << "The list is not sorted in non-decreasing order." << endl;
    }

    return 0;
}
