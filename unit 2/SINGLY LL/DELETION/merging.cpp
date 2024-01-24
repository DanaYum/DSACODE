// You are using GCC
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    
    LinkedList() : head(nullptr) {}
    
    void append(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
};

void mergeListsAlternately(LinkedList& list1, LinkedList& list2) {
    Node* current1 = list1.head;
    Node* current2 = list2.head;
    LinkedList mergedList;
    Node* currentMerged = nullptr;

    while (current1 || current2) {
        if (current1) {
            if (!currentMerged) {
                currentMerged = new Node(current1->data);
                mergedList.head = currentMerged;
            } else {
                currentMerged->next = new Node(current1->data);
                currentMerged = currentMerged->next;
            }
            current1 = current1->next;
        }
        if (current2) {
            if (!currentMerged) {
                currentMerged = new Node(current2->data);
                mergedList.head = currentMerged;
            } else {
                currentMerged->next = new Node(current2->data);
                currentMerged = currentMerged->next;
            }
            current2 = current2->next;
        }
    }
    
    // Print the merged list
    Node* current = mergedList.head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    int n, m;
    cin >> n;
    LinkedList list1, list2;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        list1.append(val);
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        int val;
        cin >> val;
        list2.append(val);
    }

    // Merge the lists alternately and print the results
    cout << "List 1: ";
    Node* current = list1.head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    cout << "List 2: ";
    current = list2.head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    cout << "Merged List: ";
    mergeListsAlternately(list1, list2);

    return 0;
}
