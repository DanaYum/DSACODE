#include <iostream>

#define MAX_Char_LENGTH 30

using namespace std;

// Function to merge two subarrays of arr[]
void merge(char arr[][MAX_Char_LENGTH], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Corrected array sizes and indexing
    char leftArr[n1][MAX_Char_LENGTH];
    char rightArr[n2][MAX_Char_LENGTH];

    // Copy data to temporary arrays leftArr[] and rightArr[]
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < MAX_Char_LENGTH; j++) {
            leftArr[i][j] = arr[left + i][j];
        }
    }

    for (int j = 0; j < n2; j++) {
        for (int k = 0; k < MAX_Char_LENGTH; k++) {
            rightArr[j][k] = arr[mid + 1 + j][k];
        }
    }

    int i = 0, j = 0, k = left;

    // Merge the two sorted subarrays back into arr[]
    while (i < n1 && j < n2) {
        if (leftArr[i][0] <= rightArr[j][0]) {
            for (int x = 0; x < MAX_Char_LENGTH; x++) {
                arr[k][x] = leftArr[i][x];
            }
            i++;
        } else {
            for (int x = 0; x < MAX_Char_LENGTH; x++) {
                arr[k][x] = rightArr[j][x];
            }
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArr[], if any
    while (i < n1) {
        for (int x = 0; x < MAX_Char_LENGTH; x++) {
            arr[k][x] = leftArr[i][x];
        }
        i++;
        k++;
    }

    // Copy the remaining elements of rightArr[], if any
    while (j < n2) {
        for (int x = 0; x < MAX_Char_LENGTH; x++) {
            arr[k][x] = rightArr[j][x];
        }
        j++;
        k++;
    }
}

// Function to perform merge sort on the array
void mergeSort(char arr[][MAX_Char_LENGTH], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int size;
    cout<<"enter size: ";
    cin >> size;

    char arr[size][MAX_Char_LENGTH];
    cout<<"enter characters you wanna sort:  ";

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    mergeSort(arr, 0, size - 1);

    cout << "Sorted Characters: ";
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < MAX_Char_LENGTH; j++) {
            if (arr[i][j] == '\0')  // Stop if null character is encountered
                break;
            cout << arr[i][j];
        }
        cout << " ";
    }
    cout << "\n";

    return 0;
}
