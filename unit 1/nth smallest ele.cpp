#include <bits/stdc++.h>
using namespace std;

int Kthsmallest(int arr[], int n, int k) {
    sort(arr, arr + n);
    return arr[k - 1];
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, k, arr[100];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> k;
    
    cout << "Original order: ";
    printArray(arr, n);

    cout << "Sorted order: ";
    sort(arr, arr + n);  // Sorting the array
    printArray(arr, n);

    cout << "The " << k << "th smallest element is: " << Kthsmallest(arr, n, k) << endl;

    return 0;
}
