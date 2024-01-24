#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

void LinkedListTraversal(struct Node* ptr) {
    while (ptr != NULL) {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

void insertion(struct Node*& head) { // Pass head as a reference
    struct Node* current = nullptr;
    int n;
    cout << "Enter the number of nodes you want to create: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        struct Node* newNode = new Node;
        cout << "Enter data for node " << i + 1 << " : ";
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
}

int main() {
    struct Node* head = nullptr; // Declare head in main
    insertion(head); // Pass head as a parameter to getNodeInput
    cout << "Linked List: " << endl;
    LinkedListTraversal(head);
    //sort.LinkedListTraversal(head);
    return 0;
}
