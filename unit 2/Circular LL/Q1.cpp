/* Lecture 12 coding Q2
Problem Statement



You have been assigned to develop a program for a ticketing system at a concert venue. The system needs to maintain a circular header-linked list to manage the available seats in the venue. Each seat is represented by a node in the list, containing the seat number (an integer) and a link to the next seat.



The program should provide the following functionality:

Insertion of a new seat at the front of the list, representing a newly available seat.
Insertion of a new seat at a specified position in the list, representing a reserved seat.
Insertion of a new seat at the middle position (take the floor value) of the list when additional seats become available due to a change in the seating arrangement.
Displaying the total number of available seats in the venue and printing the seat numbers in a circular manner, starting from the head seat.


Note: This is a sample question asked in a Capgemini interview.

Input format :
The first line contains an integer n representing the number of seats to be inserted at the front of the list.

The next line contains n seat numbers to be inserted at the front of the list.

The next line contains an integer representing the seat number to be inserted at the middle position.

The next line contains an integer position representing the position at which a seat needs to be inserted.

The next line contains an integer representing the seat number to be inserted at the specified position.

Output format :
If the list is empty or an invalid position is given, the program outputs "Invalid position.".

The program outputs "After inserting at middle:" followed by the number and list of seat numbers in a circular manner. Take the floor value while inserting it in the middle.

After inserting a seat at a specified position, the program outputs "After inserting at position:" followed by the number and list of seat numbers in a circular manner.



Refer to the sample output formatting specifications.

Code constraints :
The seat numbers are positive integers.

The maximum number of available seats is limited by the range of integers.

Sample test cases :
Input 1 :
5
15 62 30 96 70
52
4
10
Output 1 :
After inserting at middle:
No of nodes in the CLL is 6
|70| --> |96| --> |52| --> |30| --> |62| --> |15| --> 
After inserting at position 4:
No of nodes in the CLL is 7
|70| --> |96| --> |52| --> |10| --> |30| --> |62| --> |15| --> 
Input 2 :
4
10 20 30 40
50
2
60
Output 2 :
After inserting at middle:
No of nodes in the CLL is 5
|40| --> |50| --> |30| --> |20| --> |10| --> 
After inserting at position 2:
No of nodes in the CLL is 6
|40| --> |60| --> |50| --> |30| --> |20| --> |10| --> 
Input 3 :
0
Output 3 :
List is empty.
Input 4 :
3
100 120 150
500
6
400
Output 4 :
After inserting at middle:
No of nodes in the CLL is 4
|150| --> |500| --> |120| --> |100| --> 
Invalid position.
*/
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* link;
};

typedef Node* NODE;

NODE getnode() {
    NODE x = new Node();
    return x;
}

NODE insertAtFront(NODE head, int item) {
    NODE temp = getnode();
    temp->data = item;

    if (head == nullptr) {
        head = temp;
        head->link = head;
    } else {
        temp->link = head->link;
        head->link = temp;
    }

    head->data++;
    return head;
}

NODE insertAtPosition(NODE head, int item, int position) {
    if (position < 1 || position > head->data + 1) {
        cout << "Invalid position." << endl;
        return head;
    }

    NODE temp = getnode();
    temp->data = item;

    if (head == nullptr) {
        head = temp;
        head->link = head;
        head->data++;
        return head;
    } else if (position == 1) {
        return insertAtFront(head, item);
    } else {
        NODE cur = head->link;
        for (int i = 1; i < position - 1; i++) {
            cur = cur->link;
        }

        temp->link = cur->link;
        cur->link = temp;
        head->data++;
    }

    return head;
}

NODE insertInMiddle(NODE head, int item) {
    int position = (head->data + 1) / 2; // Insert at the middle position

    return insertAtPosition(head, item, position);
}

void display(NODE head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    cout << "No of nodes in the CLL is " << head->data << endl;
    NODE temp = head->link;
    do {
        cout << "|" << temp->data << "| --> ";
        temp = temp->link;
    } while (temp != head);
    cout << endl;
}

int main() {
    NODE head = nullptr;
    int n;

    head = getnode();
    head->data = 0;
    head->link = head; // Empty header node

    int value;

    cin >> n;

    if (n > 0) {
        for (int i = 0; i < n; i++) {
            cin >> value;
            head = insertAtFront(head, value);
        }

        cin >> value;
        head = insertInMiddle(head, value);

        cout << "After inserting at middle:" << endl;
        display(head);

        int position;
        cin >> position;
        if (position < 1 || position > head->data + 1) {
            cout << "Invalid position." << endl;
        } else {
            cin >> value;
            head = insertAtPosition(head, value, position);
            cout << "After inserting at position " << position << ":" << endl;
            display(head);
        }
    } else {
        cout << "List is empty." << endl;
    }

    return 0;
}
