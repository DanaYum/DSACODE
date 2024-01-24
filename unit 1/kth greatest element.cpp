#include <bits/stdc++.h>
using namespace std;

int KthLargest(int arr[], int n, int k) {
    sort(arr, arr + n, greater<int>()); // Sort in descending order
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
    sort(arr, arr + n, greater<int>()); // Sort in descending order
    printArray(arr, n);

    cout << "The " << k << "th largest element is: " << KthLargest(arr, n, k) << endl;

    // Reversing the original array to have it in descending order as well
    reverse(arr, arr + n);
    cout << "Original order (descending): ";
    printArray(arr, n);

    return 0;
}
