#include <iostream>
using namespace std;

void selectionSortPrintSteps(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        if(minIndex!=i)
        {
            int temp = arr[minIndex];
            arr[minIndex] = arr[i];
            arr[i] = temp;
        }
        
        cout << "After step " << i + 1 << ": ";
        for (int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n, arr[100];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    selectionSortPrintSteps(arr, n);
    display(arr, n);

    return 0;
}
