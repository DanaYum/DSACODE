#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insert(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void deleteMiddleNode() {
        if (head == nullptr || head->next == nullptr) {
            // The list is empty or has only one node, nothing to delete
            return;
        }

        Node* slow = head;
        Node* fast = head;
        Node* prev = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }

        // Delete the middle node
        prev->next = slow->next;
        delete slow;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    ~LinkedList() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

int main() {
    int numNodes;
    cin >> numNodes;

    LinkedList list;

    for (int i = 0; i < numNodes; i++) {
        int val;
        cin >> val;
        list.insert(val);
    }

    cout << "Original Linked List: ";
    list.display();

    list.deleteMiddleNode();

    cout << "Updated Linked List: ";
    list.display();

    return 0;
}
