#include<iostream>
#include<iomanip>
using namespace std;

void bubble(float arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        bool swapped = false; // Flag to track if any swaps occurred in this pass
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true; // Mark that a swap occurred
            }
        }
        if(!swapped) {
            // No swaps occurred in this pass, array is already sorted
            break;
        }
        
        cout << "After iteration " << i + 1 << " :";
        for(int k = 0; k < n; k++)
            cout << fixed << setprecision(2) << arr[k] << " ";
        cout << endl;
    }
}

int main() {
    int n;
    float arr[100];
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    bubble(arr, n);
    
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << fixed << setprecision(2) << arr[i] << " ";
    }

    return 0;
}
