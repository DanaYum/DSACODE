#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

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

Node* reverseInGroups(Node* head, int k) {
    Node* current = head;
    Node* prev = nullptr;
    Node* next = nullptr;
    int count = 0;

    while (current != nullptr && count < k) {
        count++;
        current = current->next;
    }

    if (count == k) {
        current = head;
        count = 0;

        while (current != nullptr && count < k) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }

        if (next != nullptr) {
            head->next = reverseInGroups(next, k);
        }

        return prev;
    }

    // If there are fewer than k nodes remaining, reverse them
    if (count < k) {
        current = head;
        prev = nullptr;

        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }

    return head;
}

void printLinkedList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = createLinkedList();
    int k;
    cin >> k;

    cout << "Original Linked List: ";
    printLinkedList(head);

    head = reverseInGroups(head, k);

    cout << "Modified Linked List: ";
    printLinkedList(head);

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
