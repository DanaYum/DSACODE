#include <iostream>
using namespace std;

void removeOs(int arr[], int &size) // Pass the size by reference
/*when we pass a variable by reference to a function, we are giving direct access to the original value
  in the memory,not a copy.This means that any modification made to the parameter inside the function will
  directly affect the original value outside the function*/
{
    int newSize = 0; // Create a new variable to keep track of non-zero elements
    for (int i = 0; i < size; i++)
    {
        if (arr[i] != 0)
        {
            arr[newSize] = arr[i]; // Move non-zero elements to the beginning of the array
            newSize++;
        }
    }
    size = newSize; // Update the size to the new size after removing zeros
}

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " "; // Add a space between elements
    }
    cout << endl; // Print a newline at the end
}

int main()
{
    int size, arr[100];
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "Removing out-of-stock products" << endl;
    cout << "Updated array of product IDs: ";
    removeOs(arr, size);
    display(arr, size);

    return 0; // Added a return statement
}
