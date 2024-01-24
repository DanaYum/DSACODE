#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void maxheap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

void insertIntoMaxHeap(int arr[], int& n, int value) {
    n++; // Increase the heap size
    int i = n - 1;
    arr[i] = value;
    
    while (i > 0 && arr[(i - 1) / 2] < arr[i]) 
    {
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
int deleteMax(int arr[], int& n) 
{

    int root = arr[0];
    arr[0] = arr[n - 1];
    n--;

    heapify(arr, n, 0);

    return root;
}


int main() {
    int n;
    int arr[100];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    maxheap(arr, n);
    cout<<arr[0];
    
    // cout << "Max heap: " << endl;
    // for (int i = 0; i < n; i++) {
    //     cout << arr[i] << " ";
    // }

    // Insert an element into the max heap
    // int value_to_insert;
    // cout << "\nEnter a value to insert: ";
    // cin >> value_to_insert;
    // insertIntoMaxHeap(arr, n, value_to_insert);

    // cout << "Max heap after insertion: " << endl;
    // for (int i = 0; i < n; i++) {
    //     cout << arr[i] << " ";
    // }
    // int max=deleteMax(arr,n);
    // cout<<"deleted root: "<<max;
    return 0;
}

