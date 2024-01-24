#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void getNodeInput(Node*& head, int n) {
    Node* current = nullptr;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            current = newNode;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }
}

void deleteOccurrences(Node*& head, int numToDelete) {
    while (head != nullptr && head->data == numToDelete) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    Node* current = head;
    while (current != nullptr && current->next != nullptr) {
        if (current->next->data == numToDelete) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        } else {
            current = current->next;
        }
    }
}

void display(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    Node* head = nullptr;

    getNodeInput(head, n);

    int numToDelete;
    cin >> numToDelete;

    cout << "Original List: ";
    display(head);

    deleteOccurrences(head, numToDelete);

    cout << "List after deleting all occurrences of " << numToDelete << ": ";
    display(head);

    // Clean up memory
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
