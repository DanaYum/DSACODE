#include <iostream>
#include <list>
using namespace std;

class Node {
public:
    string value;
    Node* next;

    Node(string value, Node* next) {
        this->value = value;
        this->next = next;
    }
};

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->value << " ";
        head = head->next;
    }
    cout << endl;
}

void insertNode(Node*& head, string value, int position) {
    Node* newNode = new Node(value, nullptr);

    if (position <= 1 || head == nullptr) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* current = head;
        int i = 1;
        while (i < position - 1 && current->next != nullptr) {
            current = current->next;
            i++;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

int main() {
    // Get the number of shifts in the schedule
    int n;
    cin >> n;

    // Create a linked list to represent the shift schedule
    Node* head = nullptr;
    for (int i = 0; i < n; i++) {
        string shift;
        cin >> shift;
        insertNode(head, shift, i + 1);
    }
    cout << "Original linked list: ";
    printList(head);
    // Get the number of shifts to left-shift the schedule
    int k;
    cin >> k;

    // Left-shift the schedule
    for (int i = 0; i < k; i++) {
        string first = head->value;
        head = head->next;
        insertNode(head, first, n + 1);
    }

    // Print the original linked list
    

    // Print the modified linked list
    cout << "Modified linked list: ";
    printList(head);

    return 0;
}