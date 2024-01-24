#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to create a linked list based on user input
void createLinkedList(Node*& head, int n) {
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
}

// Function to calculate the sum of the last k nodes
int sumOfLastKNodes(Node* head, int k) {
    Node* fast = head;
    Node* slow = head;

    // Move the fast pointer k nodes ahead
    for (int i = 0; i < k; i++) {
        if (fast == nullptr) {
            // Handle the case where k is greater than the number of nodes
            return 0;
        }
        fast = fast->next;
    }

    // Move both fast and slow pointers until the fast pointer reaches the end
    while (fast != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }

    int sum = 0;
    // Calculate the sum of the last k nodes
    while (slow != nullptr) {
        sum += slow->data;
        slow = slow->next;
    }

    return sum;
}

int main() {
    int n, k;
    Node* head = nullptr;

    // Input the size of the linked list and create it
    cin >> n;
    createLinkedList(head, n);

    // Input the value of k
    cin >> k;

    // Calculate and print the sum of the last k nodes
    int result = sumOfLastKNodes(head, k);
    cout << result << endl;

    // Free the memory allocated for the linked list nodes
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
