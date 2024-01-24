#include <iostream>
using namespace std; 

int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choose the last element as the pivot
    int tail = low - 1;  // Index of the smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) 
        {
            tail++;
            int temp=arr[j];
            arr[j]=arr[tail];
            arr[tail]=temp;
        }
    }

    int temp=arr[high];
    arr[high]=arr[tail + 1];
    arr[tail + 1]=temp;
    return tail + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Recursive calls to sort the sub-arrays
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {3,2,5,0,1,8,7,6,9,4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}
