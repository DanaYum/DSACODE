#include <iostream>
using namespace std;

// Define a structure for the linked list node that holds employee records
struct EmployeeNode {
    int employeeID;
    EmployeeNode* next;

    EmployeeNode(int id) : employeeID(id), next(nullptr) {}
};

// Create a class for the linked list
class EmployeeList {
public:
    EmployeeNode* head;

    EmployeeList() : head(nullptr) {}

    // Method to insert a new employee record at the end
    void insertEnd(int id) {
        EmployeeNode* newNode = new EmployeeNode(id);
        if (!head) {
            head = newNode;
        } else {
            EmployeeNode* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Method to split the list into two: even and odd employee IDs
    void splitEvenOddLists(EmployeeList& evenList, EmployeeList& oddList) {
        EmployeeNode* current = head;
        while (current) {
            if (current->employeeID % 2 == 0) {
                evenList.insertEnd(current->employeeID);
            } else {
                oddList.insertEnd(current->employeeID);
            }
            current = current->next;
        }
    }

    // Method to print the linked list
    void printList() {
        EmployeeNode* current = head;
        while (current) {
            cout << current->employeeID << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;

    EmployeeList employeeRecords;

    // Read input values and insert them into the linked list
    for (int i = 0; i < n; i++) {
        int id;
        cin >> id;
        employeeRecords.insertEnd(id);
    }

    EmployeeList evenList;
    EmployeeList oddList;

    // Split the list into even and odd lists
    employeeRecords.splitEvenOddLists(evenList, oddList);

    // Print the even and odd lists
    cout << "Even List: ";
    evenList.printList();

    cout << "Odd List: ";
    oddList.printList();

    return 0;
}
