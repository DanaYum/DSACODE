#include<iostream>
using namespace std;

int main() {
    int size, flag = 0;
    string arr[100];
    string element;  // Change to string type
    cout << "Enter size: ";
    cin >> size;
    cout << "Enter elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    cout << "Enter string to find its index: ";
    cin >> element;

    for (int i = 0; i < size; i++) {
        if (arr[i] == element) {
            flag = 1;
            cout << "Element found at index: " << i  << endl;
            // No need to continue searching after finding the first occurrence
            break;
        }
    }
    
    if (flag == 0) {
        cout << "Not found" << endl;
    }

    return 0;
}
