#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;
    Node(const string& value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void insert(const string& value) {
        Node* newNode = new Node(value);
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

    void deleteAlternateNodes() {
        if (head == nullptr || head->next == nullptr) {
            // The list is empty or has only one node, nothing to delete
            return;
        }

        Node* current = head;
        Node* nextNode = head->next;
        while (current != nullptr && nextNode != nullptr) {
            current->next = nextNode->next;
            delete nextNode;
            current = current->next;
            if (current != nullptr) {
                nextNode = current->next;
            }
        }
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
    int n;
    cin >> n;

    LinkedList list;

    for (int i = 0; i < n; i++) {
        string value;
        cin >> value;
        list.insert(value);
    }

    if (n == 0) {
        cout << "List is empty" << endl;
    } else {
        cout << "Linked list data: ";
        list.display();

        list.deleteAlternateNodes();

        cout << "After deleting alternate node: ";
        list.display();
    }

    return 0;
}
