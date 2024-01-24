#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> myStack;

    while (true) 
    {
        cout << "****************  Menu  **********************" << endl;
        cout << "1: Push an integer value onto the stack" << endl;
        cout << "2: Pop an integer from the stack" << endl;
        cout << "3: Display the elements currently in the stack" << endl;
        cout << "4: Exit the program" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                {
                    int value;
                    cout << "Enter an integer value to push onto the stack: ";
                    cin >> value;
                    myStack.push(value);
                    break;
                }
            case 2:
                {
                    if (myStack.empty()) {
                        cout << "Stack is empty. Cannot perform pop operation." << endl;
                    } else {
                        myStack.pop();
                        cout << "Popped an element from the stack." << endl;
                    }
                    break;
                }
            case 3:
                {
                    if (myStack.empty()) {
                        cout << "Stack is empty." << endl;
                    } else {
                        cout << "Elements in the stack:";
                        stack<int> tempStack;
                        while (!myStack.empty()) {
                            cout << " " << myStack.top();
                            tempStack.push(myStack.top());
                            myStack.pop();
                        }
                        cout << endl;

                        // Restore the stack
                        while (!tempStack.empty()) {
                            myStack.push(tempStack.top());
                            tempStack.pop();
                        }
                    }
                    break;
                }
            case 4:
                {
                    cout << "Exiting the program." << endl;
                    return 0;
                }
            default:
                {
                    cout << "Invalid choice. Please try again." << endl;
                    break;
                }
        }
    }

    return 0;
}
