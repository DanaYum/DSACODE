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

    // Method to print the data values of alternate nodes
    void printAlternateNodes() {
        if (!head) {
            cout << "Linked List is empty." << endl;
            return;
        }

        Node* current = head;
        bool alternate = true;
        cout << "Alternate Nodes: ";
        do {
            if (alternate) {
                cout << current->data << " ";
            }
            alternate = !alternate;
            current = current->next;
        } while (current != head);

        cout << endl;
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

    cll.printAlternateNodes();

    return 0;
}
