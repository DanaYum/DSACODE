#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    struct Node* next;
};

void LinkedListTraversal(struct Node* ptr) {
    while (ptr != NULL) {
        cout<< ptr->data << endl;
        ptr = ptr->next;
    }
}

void get(struct Node*& head) {
    struct Node* current = nullptr;
    int n;
    cin >> n;
    cin.ignore(); // Ignore the newline character

    for (int i = 0; i < n; i++) {
        struct Node* newNode = new Node;
        getline(cin, newNode->data); // Read string input
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

void reverseLinkedList(struct Node*& head) {
    struct Node* prev = nullptr;
    struct Node* current = head;
    struct Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}

void insertAtEnd(struct Node *&head,string str)
{
    struct Node *ptr=new Node;
    ptr->data=str;
    struct Node*p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
}

int main() {
    struct Node* head = nullptr;
    get(head);
    string str;
    cin >> str;

    cout << "Document: ";
    reverseLinkedList(head);
    LinkedListTraversal(head);
    cout << endl;

    cout << "Updated Document: ";
    insertAtEnd(head, str);
    LinkedListTraversal(head);

    return 0;
}