//sort even fisrt and after it sort odd number
#include <iostream>
using namespace std;
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArr[n1];
    int rightArr[n2];

    for (int i = 0; i < n1; ++i)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        rightArr[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && leftArr[i] % 2 == 0) {
        arr[k++] = leftArr[i++];
    }
    while (j < n2 && rightArr[j] % 2 == 0) {
        arr[k++] = rightArr[j++];
    }

    while (i < n1) {
        arr[k++] = leftArr[i++];
    }

    while (j < n2) {
        arr[k++] = rightArr[j++];
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    cout<<"enter size: ";
    cin >> n;

    int arr[n];
    cout<<"enter ele: ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    mergeSort(arr, 0, n - 1);
    cout<<"element after sorting even first, followed by sorted odd no: "<<endl;
    for (int i = 0; i < n; ++i)
    cout << arr[i] << " ";

    return 0;
}
