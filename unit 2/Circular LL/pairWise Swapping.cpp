#include <iostream>
using namespace std;

// Define a structure for the linked list node
struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

// Create a class for the circular linked list
class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList() : head(nullptr) {}

    // Method to insert a new node at the end
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

    // Method to perform pairwise swapping of adjacent elements
    void pairwiseSwap() {
        if (!head || !head->next) {
            // Empty list or only one element, no swapping needed
            return;
        }

        Node* current = head;
        Node* nextNode = head->next;

        bool isEven = true; // Flag to determine if we are in an even or odd position

        do {
            if (isEven) {
                // Swap adjacent elements
                int temp = current->data;
                current->data = nextNode->data;
                nextNode->data = temp;
            }

            current = current->next;
            nextNode = nextNode->next;
            isEven = !isEven; // Toggle the flag

        } while (current != head && nextNode != head);
    }

    // Method to print the linked list
    void printList() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;
        
        do {
            cout << current->data << " ";
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
    cout << "Original linked list: ";

    cll.printList();

    // Perform pairwise swapping for any number of inputs
    cll.pairwiseSwap();

    cout << "Linked list after pairwise swapping: ";
    cll.printList();

    return 0;
}
