// You are using GCC
#include <iostream>
using namespace std;

// Define a structure for the doubly linked list node
struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

// Create a class for the doubly linked list
class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Method to insert a new node at the end
    void insertAtEnd(int value) {
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

    // Method to reverse the doubly linked list
    void reverseList() {
        Node* current = head;
        Node* temp = nullptr;

        while (current != nullptr) {
            // Swap the prev and next pointers
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;

            // Move to the next node
            current = current->prev;
        }

        // Update the head as the tail
        if (temp != nullptr) {
            head = temp->prev;
        }
    }

    // Method to print the doubly linked list
    void printList() {
        Node* current = head;
        while (current != nullptr) {
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
        int temp;
        cin >> temp;
        dll.insertAtEnd(temp);
    }

    cout << "Original List: ";
    {//dll.printList();

    dll.reverseList();
    dll.printList();}
    cout << "Reversed List: ";
    dll.reverseList();
    dll.printList();

    return 0;
}
