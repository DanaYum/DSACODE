#include <iostream>
#include <string>
using namespace std;

// Define a structure for the doubly linked list node
struct Node {
    string data;
    Node* prev;
    Node* next;

    Node(const string& val) : data(val), prev(nullptr), next(nullptr) {}
};

// Create a class for the doubly linked list
class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Method to insert a new node at the end
    void insertAtEnd(const string& value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Method to split the doubly linked list into two equal halves
    void splitIntoHalves() {
        if (!head) {
            // The list is empty, nothing to split
            return;
        }

        Node* slow = head;
        Node* fast = head;

        // Move the fast pointer twice as fast as the slow pointer
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Split the list at the middle node
        Node* secondHalf = slow->next;
        slow->next = nullptr;

        // Print the first half
        printList(head);

        // Print the second half
        printList(secondHalf);
    }

    // Method to print the doubly linked list
    void printList(Node* start) {
        Node* current = start;
        while (current) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        dll.insertAtEnd(name);
    }

    dll.splitIntoHalves();

    return 0;
}
