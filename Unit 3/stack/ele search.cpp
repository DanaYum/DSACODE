#include <iostream>
using namespace std;
const int MAX_STACK_SIZE = 30;

class Stack {
private:
    int arr[MAX_STACK_SIZE];
    int top;

public:
    Stack() : top(-1) {}

    void push(int element) {
        if (top == MAX_STACK_SIZE - 1) {
            cout << "STACK is overflow" << endl;
        } else {
            arr[++top] = element;
        }
    }

    void search(int element) {
        if (top == -1) {
            cout << "The STACK is empty" <<endl;
            return;
        }

        for (int i = top; i >= 0; --i) {
            if (arr[i] == element) {
                cout << "Element found" << endl;
                return;
            }
        }

        cout << "Element not found" <<endl;
    }
};

int main() {
    Stack stack;
    cout<<"enter n: ";
    int n;

   
   cin >> n;
    cout<<"enter the elements: "<<endl;

    for (int i = 0; i < n; ++i) {
        int element;
        cin >> element;
        stack.push(element);
    }

    int searchElement;
    cout<<"enter number to search: ";
   cin >> searchElement;

    stack.search(searchElement);

    return 0;
}